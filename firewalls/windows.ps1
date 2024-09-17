# -- Allow HTTP (port 80) --
New-NetFirewallRule -DisplayName "Allow_HTTP" -Direction Inbound -LocalPort 80 -Protocol TCP -Action Allow

# -- Allow HTTPS (port 443) --
New-NetFirewallRule -DisplayName "Allow_HTTPS" -Direction Inbound -LocalPort 443 -Protocol TCP -Action Allow

# -- Deny SSH (port 22) --
New-NetFirewallRule -DisplayName "Deny_SSH" -Direction Inbound -LocalPort 22 -Protocol TCP -Action Block

# -- Allow FTP (port 21) --
New-NetFirewallRule -DisplayName "Allow_FTP" -Direction Inbound -LocalPort 21 -Protocol TCP -Action Allow

# -- Deny RDP (port 3389) --
New-NetFirewallRule -DisplayName "Deny_RDP" -Direction Inbound -LocalPort 3389 -Protocol TCP -Action Block


Write-Host "success.."
