git ls-tree -r HEAD --name-only benchmark example memprof td tdactor tdcpr tddb tdnet tdtl tdutils test tg_http_client | Select-String "\.cpp$|\.h$|\.hpp$"
