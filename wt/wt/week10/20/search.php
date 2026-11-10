<?php
// Set header to return JSON data
header('Content-Type: application/json');

// Get the search query from the URL (e.g., search.php?q=Alice)
$query = isset($_GET['q']) ? strtolower(trim($_GET['q'])) : '';

$jsonFile = 'employees.json';
$results = [];

if (file_exists($jsonFile)) {
    $jsonData = file_get_contents($jsonFile);
    $employees = json_decode($jsonData, true);

    if ($employees !== null) {
        // If the search box is empty, return all employees
        if ($query === '') {
            $results = $employees;
        } else {
            // Filter employees based on Name, ID, or Department
            foreach ($employees as $emp) {
                if (
                    strpos(strtolower($emp['name']), $query) !== false ||
                    strpos(strtolower($emp['emp_id']), $query) !== false ||
                    strpos(strtolower($emp['department']), $query) !== false
                ) {
                    $results[] = $emp;
                }
            }
        }
    }
}

// Return the filtered results as JSON to the frontend
echo json_encode($results);
?>