async function putRequest(url: string, body) {
    console.log(`---> PUT ${url}\n - BODY:`, body);

    const headers = new Headers();
    headers.append("Content-Type", "application/json; charset=utf-8");
    
    const res = await fetch(url, {
        method: "PUT",
        body: JSON.stringify(body),

        headers: headers
    });

    console.log(`<--- PUT ${res.status} ${url}`);

    const resData = await res.json();
    return resData;
}

export default putRequest;