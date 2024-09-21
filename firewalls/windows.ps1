$rules = @(
  # ------------ Inbound | Allow ------------
    # Allow HTTP (port 80)
    @("0_FW_HTTP_INBOUND_ALLOW", "Inbound", 80, "TCP", "Allow"),

    # Allow HTTPS (port 443)
    @("0_FW_HTTPS_INBOUND_ALLOW", "Inbound", 443, "TCP", "Allow"),

    # Allow FTP (port 21)
    @("0_FW_FTP_INBOUND_ALLOW", "Inbound", 21, "TCP", "Allow"),

    # Allow FTPS (port 990)
    @("0_FW_FTPS_INBOUND_ALLOW", "Inbound", 990, "TCP", "Allow"),

    # Allow SMTP (port 25)
    @("0_FW_SMTP_INBOUND_ALLOW", "Inbound", 25, "TCP", "Allow"),

    # Allow SMTPS (port 587)
    @("0_FW_SMTPS_INBOUND_ALLOW", "Inbound", 587, "TCP", "Allow"),

    # Allow DNS (port 53)
    @("0_FW_DNS_INBOUND_ALLOW", "Inbound", 53, "TCP", "Allow"),
  # ------------ Inbound | Allow ------------



  # ------------ Inbound | Block ------------
    # Attacker (port 4444, 6666, 8080)
    @("0_FW_ATTACKER_INBOUND_BLOCK_4444", "Inbound", 4444, "TCP", "Block"),
    @("0_FW_ATTACKER_INBOUND_BLOCK_6666", "Inbound", 6666, "TCP", "Block"),
    @("0_FW_ATTACKER_INBOUND_BLOCK_8080", "Inbound", 8080, "TCP", "Block"),
    @("0_FW_ATTACKER_INBOUND_BLOCK_8888", "Inbound", 8888, "TCP", "Block"),

  # ------------ Inbound | Block ------------


  # ------------ Outbound | Allow ------------
    # Allow HTTP (port 80)
    @("0_FW_HTTP_OUTBOUND_ALLOW", "Outbound", 80, "TCP", "Allow"),

    # Allow HTTPS (port 443)
    @("0_FW_HTTPS_OUTBOUND_ALLOW", "Outbound", 443, "TCP", "Allow"),

    # Allow FTP (port 21)
    @("0_FW_FTP_OUTBOUND_ALLOW", "Outbound", 21, "TCP", "Allow"),

    # Allow SMTP (port 25)
    @("0_FW_SMTP_OUTBOUND_ALLOW", "Outbound", 25, "TCP", "Allow")
  # ------------ Outbound | Allow ------------
)

foreach ($rule in $rules) {
  New-NetFirewallRule -DisplayName $rule[0] -Direction $rule[1] -LocalPort $rule[2] -Protocol $rule[3] -Action $rule[4]
  Write-Host "[" $rule[4] "]" "DisplayName="$rule[0] "Direction="$rule[1] "LocalPort="$rule[2] "Protocol="$rule[3]
}
