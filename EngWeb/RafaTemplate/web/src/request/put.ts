async function putRequest(url: string, body: Record<string, unknown>, debug: boolean = false) {
    console.log(`---> PUT ${url}\n - BODY:`, body);

    const headers = new Headers();
    headers.append("Content-Type", "application/json; charset=utf-8");
    
    const res = await fetch(url, {
        method: "PUT",
        body: JSON.stringify(body),

        headers: headers
    });

    console.log(`<--- PUT ${res.status} ${url}`);
    if (!res.ok) throw new Error(`Request failed : ${url}`);

    // const resData = await res.json();
    // return resData;
    const resData = debug ? await res.text() : await res.json();
    return resData;
}

export default putRequest;