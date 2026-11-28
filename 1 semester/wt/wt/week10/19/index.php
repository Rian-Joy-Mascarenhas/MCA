<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Employee Details</title>
    <style>
        body { font-family: Arial, sans-serif; background-color: #f4f4f9; padding: 20px; }
        .container { max-width: 800px; margin: 0 auto; background: #fff; padding: 20px; border-radius: 8px; box-shadow: 0 4px 8px rgba(0,0,0,0.1); }
        h2 { text-align: center; color: #333; }
        table { width: 100%; border-collapse: collapse; margin-top: 20px; }
        th, td { padding: 12px; text-align: left; border-bottom: 1px solid #ddd; }
        th { background-color: #007bff; color: white; }
        tr:hover { background-color: #f1f1f1; }
        .error { color: red; text-align: center; font-weight: bold; }
    </style>
</head>
<body>

<div class="container">
    <h2>Employee Directory</h2>

    <?php
    $jsonFile = 'employees.json';

    // Check if the JSON file exists
    if (file_exists($jsonFile)) {
        // Read the JSON file content
        $jsonData = file_get_contents($jsonFile);
        
        // Decode the JSON data into a PHP associative array (true makes it an array instead of an object)
        $employees = json_decode($jsonData, true);

        // Check if JSON decoding was successful
        if ($employees !== null) {
            echo "<table>";
            echo "<tr>
                    <th>Emp ID</th>
                    <th>Name</th>
                    <th>Designation</th>
                    <th>Department</th>
                    <th>Salary ($)</th>
                  </tr>";

            // Loop through the array and display each employee's details
            foreach ($employees as $emp) {
                echo "<tr>";
                echo "<td>" . htmlspecialchars($emp['emp_id']) . "</td>";
                echo "<td>" . htmlspecialchars($emp['name']) . "</td>";
                echo "<td>" . htmlspecialchars($emp['designation']) . "</td>";
                echo "<td>" . htmlspecialchars($emp['department']) . "</td>";
                echo "<td>$" . number_format($emp['salary']) . "</td>";
                echo "</tr>";
            }
            
            echo "</table>";
        } else {
            echo "<p class='error'>Error decoding the JSON data.</p>";
        }
    } else {
        echo "<p class='error'>Error: The file '$jsonFile' was not found.</p>";
    }
    ?>
</div>

</body>
</html>