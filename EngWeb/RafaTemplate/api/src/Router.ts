import fs from "fs";
// import fsp from "fs/promises";
import path from "path";
import { Router as _Router, type Express } from "express";
import { readDirFlat } from "./util/path.js";

const __dirname = import.meta.dirname;

abstract class Router {
    private static priority: number = 0;
    protected router: _Router;
    public route: string;

    constructor(route: string) {
        this.router = _Router();
        this.route = route;
    }

    public get(): _Router {
        return this.router;
    }

    public abstract init(app: Express): Promise<void>;
}

async function loadRouters(dir: string): Promise<Router[]> {
    const fullPath = path.resolve(dir);
    if (!fs.existsSync(fullPath)) throw new Error(`Could not load routers: ENOENT ${fullPath}`);

    const routers = <Router[]>[];
    const routerPaths = await readDirFlat(fullPath, fullPath);
    for (const routerPath of routerPaths) {
        if (!routerPath.endsWith(".js")) {
            if (routerPath.endsWith(".ts")) {
                if (routerPath.endsWith(".d.ts")) continue;
            } else continue;
        }
        
        const RouterClass = <{ new(): Router }>(await import(routerPath)).default;
        const router: Router = new RouterClass();
        routers.push(router);
    }

    return routers;
}

export default Router;
export {
    loadRouters
};