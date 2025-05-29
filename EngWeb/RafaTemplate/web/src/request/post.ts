async function postRequest(url: string, body: Record<string, unknown>, debug: boolean = false) {
    console.log(`---> POST ${url}\n - BODY:`, body);

    const headers = new Headers();
    headers.append("Content-Type", "application/json; charset=utf-8");
    
    const res = await fetch(url, {
        method: "POST",
        body: JSON.stringify(body),

        headers: headers
    });

    console.log(`<--- POST ${res.status} ${url}`);
    if (!res.ok) throw new Error(`Request failed : ${url}`);

    const resData = debug ? await res.text() : await res.json();
    return resData;
}

export default postRequest;