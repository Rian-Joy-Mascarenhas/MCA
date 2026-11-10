<?php
// Set your default timezone (Optional, but ensures accurate local time)
date_default_timezone_set('Asia/Kolkata');

$cookie_name = "last_visit";
$current_time = date("Y-m-d h:i:s A"); 
$cookie_expiration = time() + (86400 * 30); // 86400 = 1 day. Cookie expires in 30 days.

// Check if the cookie already exists
if(isset($_COOKIE[$cookie_name])) {
    $last_visit_time = $_COOKIE[$cookie_name];
    $message = "Welcome back! Your last visit was on: <strong>" . htmlspecialchars($last_visit_time) . "</strong>";
} else {
    $message = "Welcome! This is your first visit to this page.";
}

// Update the cookie with the NEW current time for the next visit
// Note: setcookie() MUST be called before any HTML output is generated
setcookie($cookie_name, $current_time, $cookie_expiration, "/");
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Last Visit Cookie</title>
    <style>
        body { font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; background-color: #f0f4f8; display: flex; justify-content: center; padding-top: 100px; margin: 0; }
        .card { background: white; padding: 30px; border-radius: 10px; box-shadow: 0 4px 8px rgba(0,0,0,0.1); text-align: center; max-width: 400px; width: 100%; }
        h2 { color: #333; margin-top: 0; }
        p { color: #555; font-size: 16px; line-height: 1.5; }
        .hint { margin-top: 20px; font-size: 13px; color: #888; }
    </style>
</head>
<body>
    <div class="card">
        <h2>Cookie Tracker</h2>
        <p><?php echo $message; ?></p>
        
        <div class="hint">
            <p><em>Refresh this page to see the cookie in action! The time displayed above will update to your previous refresh time.</em></p>
        </div>
    </div>

</body>
</html>