async function getRequest(url: string) {
    console.log(`---> GET ${url}`);

    const res = await fetch(url, {
        method: "GET"
    });

    console.log(`<--- GET ${res.status} ${url}`);
    const resData = await res.json();
    return resData;
}

export default getRequest;