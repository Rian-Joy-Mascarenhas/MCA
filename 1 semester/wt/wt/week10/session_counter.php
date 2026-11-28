<?php
// session_start() must be the very first thing in your script, before any HTML
session_start();

// Check if the user clicked the 'Reset' button
if (isset($_POST['reset'])) {
    // Destroy all session data
    session_unset();
    session_destroy();
    
    // Refresh the page to start over
    header("Location: " . $_SERVER['PHP_SELF']);
    exit;
}

// Check if the 'views' session variable already exists
if (isset($_SESSION['views'])) {
    // If it exists, increment the counter by 1
    $_SESSION['views'] = $_SESSION['views'] + 1;
} else {
    // If it doesn't exist (first visit this session), set it to 1
    $_SESSION['views'] = 1;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Session Page Counter</title>
    <style>
        body { font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; background-color: #e9ecef; display: flex; justify-content: center; padding-top: 100px; margin: 0; }
        .card { background: white; padding: 40px; border-radius: 10px; box-shadow: 0 4px 15px rgba(0,0,0,0.1); text-align: center; max-width: 400px; width: 100%; }
        h2 { color: #333; margin-top: 0; }
        .count-display { font-size: 48px; font-weight: bold; color: #007bff; margin: 20px 0; }
        p { color: #555; font-size: 16px; line-height: 1.5; }
        .hint { margin-top: 25px; font-size: 13px; color: #888; background: #f8f9fa; padding: 10px; border-radius: 5px;}
        button { margin-top: 15px; padding: 10px 20px; background-color: #dc3545; color: white; border: none; border-radius: 4px; cursor: pointer; font-size: 14px; transition: 0.2s;}
        button:hover { background-color: #c82333; }
    </style>
</head>
<body>

    <div class="card">
        <h2>Session Views Counter</h2>
        <p>You have refreshed this page:</p>
        
        <div class="count-display">
            <?php echo $_SESSION['views']; ?>
        </div>
        <p>time(s) during this browser session.</p>

        <form method="POST">
            <button type="submit" name="reset">Reset Counter</button>
        </form>
        
        <div class="hint">
            <p><strong>Try it:</strong> Refresh the page to see the number go up. If you close your entire browser and open this page again, the count will reset to 1 because the session ends.</p>
        </div>
    </div>

</body>
</html>