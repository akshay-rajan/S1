<html>
    <head></head>
    <body>
        <h1>Add Book</h1>
        <form action="" method="post">
            Title: <input type="text" name="title">
            Author: <input type="text" name="author"><br>
            No. of copies:
            <select name="copies">
                <option value="SELECT" selected disabled>SELECT</option>
                <?php
                    session_start();
                    for ($i = 10000; $i < 1000000; $i += 10000) {
                    echo "<option value='{$i}'>{$i}</option>";
                } ?>
            </select>
            <input type="submit" value="Add" name="add">
        </form>

        <?php 
            $conn = mysqli_connect("localhost", "root", "", "library");
            if (!$conn) {
                echo mysqli_error($conn);
            } else {
                if (isset($_POST["add"])) {
                    $name = $_POST['title'];
                    $author = $_POST['author'];
                    $copies = $_POST['copies'];
                    $sql = "INSERT INTO book (name, author, copies) VALUES ('$name', '$author', '$copies')";
                    $result = mysqli_query($conn, $sql);
                    if ($result) {
                        echo "<h2>Book Added Successfully!</h2>";
                    } else {
                        echo mysqli_error($conn);
                    }
                }
            }
        ?>
    </body>
</html>