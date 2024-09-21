powershell -Command "Start-Process ./firewalls.exe -ArgumentList '--rules ./rules/tcp_inbound_allow.json' -Verb RunAs"
powershell -Command "Start-Process ./firewalls.exe -ArgumentList '--rules ./rules/tcp_outbound_allow.json' -Verb RunAs"
powershell -Command "Start-Process ./firewalls.exe -ArgumentList '--rules ./rules/tcp_inbound_deny.json' -Verb RunAs"
powershell -Command "Start-Process ./firewalls.exe -ArgumentList '--rules ./rules/tcp_outbound_deny.json' -Verb RunAs"
