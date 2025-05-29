import { type Express } from "express";
import Router from "../Router.js";
import { createContrato, getContratos, getDistinctContracts, getSingleContrato, killContrato } from "../db/controllers/Contrato.js";

class ContratosRouter extends Router {
    constructor() {
        super("/contratos");
    }

    public async init(_app: Express): Promise<void> {
        console.log("  - Initializing api 'contratos' router...");

        this.router.get("/", async (req, res) => {
            const { entidade, nipcEntidade, tipo } = req.query;

            if (entidade !== undefined) {
                const contracts = await getContratos({ entidade_comunicante: String(entidade) });
                const json = contracts.map(c => c.toJSON());
                res.json(json);
            } else if (nipcEntidade !== undefined) {
                const contracts = await getContratos({ NIPC_entidade_comunicante: String(nipcEntidade) });
                const json = contracts.map(c => c.toJSON());
                res.json(json);
            } else if (tipo !== undefined) {
                const contracts = await getContratos({ tipoprocedimento: String(tipo) });
                const json = contracts.map(c => c.toJSON());
                res.json(json);
            } else {
                const contracts = await getContratos();
                const json = contracts.map(c => c.toJSON());
                res.json(json);
            }
        });

        this.router.post("/", async (req, res) => {
            const requiredKeys = [
                "idcontrato",
                "nAnuncio",
                "tipoprocedimento",
                "objectoContrato",
                "dataPublicacao",
                "dataCelebracaoContrato",
                "precoContratual",
                "prazoExecucao",
                "NIPC_entidade_comunicante",
                "entidade_comunicante",
                "fundamentacao",
            ];

            const bKeys = Object.keys(req.body);
            if (requiredKeys.some(k => !bKeys.includes(k))) {
                res.status(400).send("Missing keys.");
                return;
            }

            const obj = Object.fromEntries(Object.entries(req.body).filter(([k,_]) => requiredKeys.includes(k)));
            await createContrato(obj);

            res.status(200).send();
            return;
        });

        this.router.get("/entidades", async (_req, res) => {
            const contracts = await getDistinctContracts("entidade_comunicante");
            res.json(contracts);
        });

        this.router.get("/tipos", async (_req, res) => {
            const contracts = await getDistinctContracts("tipoprocedimento");
            res.json(contracts);
        });

        this.router.get("/:id", async (_req, res) => {
            const contracts = await getContratos({ idcontrato: _req.params.id });
            const json = contracts.map(c => c.toJSON());
            res.json(json);
        });

        this.router.delete("/:id", async (_req, res) => {
            await killContrato({ idcontrato: _req.params.id });
            res.status(200).send();
        });

        this.router.put("/:id", async (req, res) => {
            const contract = await getSingleContrato({ idcontrato: req.params.id });
            if (!contract) {
                res.status(400).send("No existing contract.");
                return;
            }

            const requiredKeys = [
                "idcontrato",
                "nAnuncio",
                "tipoprocedimento",
                "objectoContrato",
                "dataPublicacao",
                "dataCelebracaoContrato",
                "precoContratual",
                "prazoExecucao",
                "NIPC_entidade_comunicante",
                "entidade_comunicante",
                "fundamentacao",
            ];
            
            const obj = Object.fromEntries(Object.entries(req.body).filter(([k,_]) => requiredKeys.includes(k)));
            Object.assign(contract, obj);

            await contract.save();

            res.status(200).send();
            return;
        });
    }
}

export default ContratosRouter;