$routerIP = "192.168.1.1"
$user = "qywok"
$password = "AbAcAdAbrA123"

$plinkPath = "C:\Program Files\PuTTY\plink.exe"
$commands = @(
    "enable",
    "configure terminal",
    "firewall zone trust",

    # -- Allow HTTP (port 80) --
    "firewall policy 3000 permit",
    "rule name Allow_HTTP",
    "source any",
    "destination any",
    "service tcp 80",
    "commit",

    # -- Allow HTTPS (port 443) --
    "firewall policy 3001 permit",
    "rule name Allow_HTTPS",
    "source any",
    "destination any",
    "service tcp 443",
    "commit",

    # -- Deny SSH (port 22) --
    "firewall policy 3002 deny",
    "rule name Deny_SSH",
    "source any",
    "destination any",
    "service tcp 22",
    "commit",

    "exit",
    "write memory",
    "exit"
)


foreach ($command in $commands) {
    $cmd = "& '$plinkPath' -telnet $routerIP -l $user -pw $password $command"
    Invoke-Expression $cmd
    Start-Sleep -Seconds 1
}

Write-Host "Success.."
