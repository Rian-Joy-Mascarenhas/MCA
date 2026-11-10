<?php
// Define the upload directory and maximum file size (5MB)
$uploadDir = 'uploads/';
$maxFileSize = 5 * 1024 * 1024; 
$message = '';

// Create the uploads directory if it doesn't exist
if (!is_dir($uploadDir)) {
    mkdir($uploadDir, 0755, true);
}

if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_FILES['resume'])) {
    $file = $_FILES['resume'];
    
    // 1. Check for basic upload errors
    if ($file['error'] !== UPLOAD_ERR_OK) {
        $message = "<span style='color:red;'>Error uploading file. Error code: {$file['error']}</span>";
    } else {
        // 2. Validate file size
        if ($file['size'] > $maxFileSize) {
            $message = "<span style='color:red;'>File is too large. Maximum size is 5MB.</span>";
        } else {
            // 3. Validate file extension
            $fileExtension = strtolower(pathinfo($file['name'], PATHINFO_EXTENSION));
            if ($fileExtension !== 'pdf') {
                $message = "<span style='color:red;'>Invalid file type. Only PDF files are allowed.</span>";
            } else {
                // 4. Validate MIME type securely using finfo
                $finfo = finfo_open(FILEINFO_MIME_TYPE);
                $mimeType = finfo_file($finfo, $file['tmp_name']);
                finfo_close($finfo);

                if ($mimeType !== 'application/pdf') {
                    $message = "<span style='color:red;'>The file content is not a valid PDF.</span>";
                } else {
                    // 5. Generate a unique filename to prevent overwriting existing files
                    $newFileName = uniqid('resume_', true) . '.pdf';
                    $destination = $uploadDir . $newFileName;

                    // 6. Move the file from the temporary directory to the uploads folder
                    if (move_uploaded_file($file['tmp_name'], $destination)) {
                        $message = "<span style='color:green;'>Resume uploaded successfully! File saved as: {$newFileName}</span>";
                    } else {
                        $message = "<span style='color:red;'>Failed to move the uploaded file. Check folder permissions.</span>";
                    }
                }
            }
        }
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Resume Upload</title>
    <style>
        body { font-family: Arial, sans-serif; background-color: #f4f4f9; padding: 20px; }
        .upload-container { max-width: 400px; background: #fff; padding: 20px; border-radius: 8px; box-shadow: 0 4px 6px rgba(0,0,0,0.1); margin: 0 auto; }
        h2 { text-align: center; color: #333; }
        .message { text-align: center; margin-bottom: 15px; font-weight: bold; }
        input[type="file"] { display: block; width: 100%; margin-bottom: 15px; }
        button { width: 100%; padding: 10px; background-color: #007bff; color: white; border: none; border-radius: 4px; cursor: pointer; }
        button:hover { background-color: #0056b3; }
    </style>
</head>
<body>

<div class="upload-container">
    <h2>Upload Your Resume</h2>
    <?php if ($message): ?>
        <div class="message"><?php echo $message; ?></div>
    <?php endif; ?>

    <!-- Note: enctype="multipart/form-data" is strictly required for file uploads -->
    <form action="upload.php" method="POST" enctype="multipart/form-data">
        <label for="resume">Select PDF Resume (Max 5MB):</label>
        <input type="file" name="resume" id="resume" accept=".pdf" required>
        <button type="submit">Upload Resume</button>
    </form>
</div>
</body>
</html>