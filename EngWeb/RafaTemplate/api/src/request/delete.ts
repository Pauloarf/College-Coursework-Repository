async function deleteRequest(url: string) {
    console.log(`---> DELETE ${url}`);

    const res = await fetch(url, {
        method: "DELETE"
    });

    console.log(`<--- DELETE ${res.status} ${url}`);
    return res;
}

export default deleteRequest;