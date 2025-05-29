const _SAFE_QUERY     = (base: string, prop: string)                  => `${base}${base.includes("?") ? "&" : "?"}${prop}`;
const TARGET          = (base: string, target: string)                => `${base}${base.endsWith("/") ? "" : "/"}${target}`;
const INCLUDE         = (base: string, prop: string)                  => _SAFE_QUERY(base, `_embed=${prop}`);
const INCLUDE_REVERSE = (base: string, prop: string)                  => _SAFE_QUERY(base, `_expand=${prop}`);
const LIMIT           = (base: string, limit: number)                 => _SAFE_QUERY(base, `_limit=${limit}`);
const BOUND           = (base: string, start: number, end: number)    => _SAFE_QUERY(base, `_start=${start}&_end=${end}`);
const SORT            = (base: string, sort: string, order: string)   => _SAFE_QUERY(base, `_sort=${sort}&order=${order}`);
const FILTER          = (base: string, props: Record<string, string>) => Object.entries(props)
    .reduce((acc, [k,v]) => _SAFE_QUERY(acc, `${k}=${encodeURIComponent(v)}`), base);
const FILTER_MULTI    = (base: string, key: string, values: string[]) => values
    .reduce((acc, v) => _SAFE_QUERY(acc, `${key}=${encodeURIComponent(v)}`), base);
const FILTER_ARRAY    = (base: string, key: string, values: string[]) => values
    .reduce((acc, v) => _SAFE_QUERY(acc, `${key}_like=${encodeURIComponent(v)}`), base);

export {
    TARGET,
    INCLUDE,
    INCLUDE_REVERSE,
    LIMIT,
    BOUND,
    SORT,
    FILTER,
    FILTER_MULTI,
    FILTER_ARRAY
};