async function getRequest(url: string, debug: boolean = false) {
    console.log(`---> GET ${url}`);

    const res = await fetch(url, {
        method: "GET"
    });

    console.log(`<--- GET ${res.status} ${url}`);
    if (!res.ok) throw new Error(`Request failed : ${url}`);

    // const resData = await res.json();
    // return resData;
    const resData = debug ? await res.text() : await res.json();
    return resData;
}

export default getRequest;