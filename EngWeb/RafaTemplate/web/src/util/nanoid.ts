import crypto from "crypto";

const SOURCE = "useandom-26T198340PX75pxJACKVERYMINDBUSHWOLF_GQZbfghjklqvwyzrict";

export const nanoid = (len = 21) => {
    let id = "";
    const rand = crypto.getRandomValues(new Uint8Array(len));

    for(let n = 0; n < len; n++) id += SOURCE[63 & rand[n]];
    return id;
};