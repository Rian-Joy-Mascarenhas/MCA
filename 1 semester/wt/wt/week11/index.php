<?php
// Connect to the database
$conn = mysqli_connect("localhost", "root", "", "library");

// CREATE (Insert)
if (isset($_POST['save'])) {
    $acc = $_POST['access_no'];
    $title = $_POST['title'];
    $author = $_POST['author'];
    $edition = $_POST['edition'];
    $pub = $_POST['publisher'];
    
    mysqli_query($conn, "INSERT INTO books VALUES ('$acc', '$title', '$author', '$edition', '$pub')");
}

// UPDATE
if (isset($_POST['update'])) {
    $acc = $_POST['access_no'];
    $title = $_POST['title'];
    $author = $_POST['author'];
    $edition = $_POST['edition'];
    $pub = $_POST['publisher'];
    
    mysqli_query($conn, "UPDATE books SET title='$title', author='$author', edition='$edition', publisher='$pub' WHERE access_no='$acc'");
}

// DELETE
if (isset($_GET['delete'])) {
    $acc = $_GET['delete'];
    mysqli_query($conn, "DELETE FROM books WHERE access_no='$acc'");
}
?>

<!DOCTYPE html>
<html>
<body>
    <h2>Library Book Management</h2>
    
    <!-- HTML Form -->
    <form method="POST">
        Accession No: <input type="text" name="access_no" required><br><br>
        Title: <input type="text" name="title"><br><br>
        Authors: <input type="text" name="author"><br><br>
        Edition: <input type="text" name="edition"><br><br>
        Publisher: <input type="text" name="publisher"><br><br>
        
        <input type="submit" name="save" value="Create / Save">
        <input type="submit" name="update" value="Update">
    </form>
    <br><br>

    <!-- Display Table -->
    <table border="1">
        <tr>
            <th>Accession No</th>
            <th>Title</th>
            <th>Authors</th>
            <th>Edition</th>
            <th>Publisher</th>
            <th>Action</th>
        </tr>
        
        <?php
        // READ (Display)
        $result = mysqli_query($conn, "SELECT * FROM books");
        while ($row = mysqli_fetch_assoc($result)) {
            echo "<tr>";
            echo "<td>" . $row['access_no'] . "</td>";
            echo "<td>" . $row['title'] . "</td>";
            echo "<td>" . $row['author'] . "</td>";
            echo "<td>" . $row['edition'] . "</td>";
            echo "<td>" . $row['publisher'] . "</td>";
            echo "<td><a href='?delete=" . $row['access_no'] . "'>Delete</a></td>";
            echo "</tr>";
        }
        ?>
    </table>
</body>
</html>

<!--
CREATE DATABASE library;
USE library;
CREATE TABLE books (
    access_no VARCHAR(20) PRIMARY KEY,
    title VARCHAR(50),
    author VARCHAR(50),
    edition VARCHAR(20),
    publisher VARCHAR(50)
);
-->