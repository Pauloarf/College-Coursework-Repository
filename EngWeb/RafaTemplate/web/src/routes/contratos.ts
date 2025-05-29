import { type Express } from "express";
import Router from "../Router.js";
import { FILTER } from "src/api.js";
import getRequest from "src/request/get.js";

const API_BASE = process.env.API_URI ?? "http://localhost:16000/contratos";

async function getContratos(filter?: Record<string, string>): Promise<Record<string, unknown>[] | undefined> {
    try {
        const request_url = filter ? FILTER(API_BASE, filter) : API_BASE;
        const data = await getRequest(request_url);

        return <Record<string, unknown>[]>data;
    } catch(e) {
        console.error(e);
        return undefined;
    }
}

class BaseRouter extends Router {
    constructor() {
        super("/");
    }

    public async init(_app: Express): Promise<void> {
        console.log("  - Initializing api 'contratos' router...");

        this.router.get("/contratos", async (_req, res) => {
            const contracts = await getContratos();

            res.render("contratos", { lcontracts: contracts });
        });

        this.router.get("/entidades/:nipc", async (_req, res) => {
            const contracts = await getContratos({ nipcEntidade: _req.params.nipc });
            if (contracts === undefined || contracts.length === 0) throw new Error(`Entidade não existente.`);

            const entity = {
                name: contracts[0].entidade_comunicante,
                nipc: _req.params.nipc,
                totalValue: contracts.reduce((acc, cur) => acc += Number(cur.precoContratual), 0)
            };

            res.render("entidade", { entity: entity, lcontracts: contracts });
        });

        this.router.get("/:id", async (_req, res) => {
            const contract = await getContratos({ idcontrato: _req.params.id });

            res.render("contrato", { contract: (contract ?? [])[0] });
        });
    }
}

export default BaseRouter;