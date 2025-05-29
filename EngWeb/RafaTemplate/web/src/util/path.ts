// import fs from "fs";
import fsp from "fs/promises";
import path from "path";

async function readDirFlat(dirname: string, root: string = ""): Promise<string[]> {
    const files = <string[]>[];

    const dirfiles = await fsp.readdir(dirname, { withFileTypes: true });
    for (const entry of dirfiles) {
        if (entry.isFile()) files.push(path.join(root, entry.name));
        else if (entry.isDirectory()) {
            const ndirfiles = await readDirFlat(path.join(dirname, entry.name), path.join(root, entry.name));
            files.push(...ndirfiles);
        }
    }

    return files;
}

export {
    readDirFlat
};