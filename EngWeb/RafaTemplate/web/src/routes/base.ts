import { type Express } from "express";
import Router from "../Router.js";

class BaseRouter extends Router {
    constructor() {
        super("/");
    }

    public async init(_app: Express): Promise<void> {
        console.log("  - Initializing base router...");
        this.router.get("/", (_req, res) => {
            res.render("index", { title: "Express", docente: "jcr", instituicao: "DI-UM" });
        });
    }
}

export default BaseRouter;