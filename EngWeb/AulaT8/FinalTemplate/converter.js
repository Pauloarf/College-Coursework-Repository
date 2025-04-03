import fsp from "fs/promises";

const dsfd = await fsp.readFile(".db/dataset/db.json", { encoding: "utf8" });
const ds = JSON.parse(dsfd);

const nds = ds.map(e => {
    e.bookId = Number(e.bookId.match(/^\d+/)![0]);
    if (e.genres.startsWith("[")) e.genres = eval(e.genres);
    if (e.characters.startsWith("[")) e.characters = eval(e.characters);
    if (e.awards.startsWith("[")) e.awards = eval(e.awards);
    if (e.ratingsByStars.startsWith("[")) e.ratingsByStars = eval(e.ratingsByStars).map(Number);
    if (e.setting.startsWith("[")) e.setting = eval(e.setting);

    e.rating = Number(e.rating);
    e.numRatings = Number(e.numRatings);
    e.likedPercent = Number(e.likedPercent);
    e.bbeScore = Number(e.bbeScore);
    e.bbeVotes = Number(e.bbeVotes);
    e.price = Number(e.price);
    e.pages = Number(e.pages);


    return e;
});

await fsp.writeFile("./dataset/db2.json", JSON.stringify(nds), { encoding: "utf8" });