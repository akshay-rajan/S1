<form action="" method="POST">
    Select a student: <select name="ktuid">
        <option value="none" selected disabled>SELECT</option>
        <?php 
            $conn = mysqli_connect('localhost', 'root', '', 'registration');
            if (!$conn) {
                echo "Cannot connect!";
            } else {

                $sql = "SELECT ktu_id FROM users";
                $result = mysqli_query($conn, $sql);
                if ($result) {
                    while ($row = mysqli_fetch_assoc($result)) {
                        echo "<option value={$row['ktu_id']}>{$row['ktu_id']}</option>";
                    }
                } else {
                    echo "No data.";
                }

            }
        ?>
    </select>
    <input type="submit" value="Get Marks" name="getmarks">
</form>
<?php 

    // Fetch marks from the database
    if ($_POST['getmarks']) {
        $ktu_id = $_POST['ktu_id'];
        $q = "SELECT * FROM marks WHERE ktu_id='$ktu_id'";
        $res = mysqli_query($conn, $q);
        if ($res) {
            $row = mysqli_fetch_assoc($res);
            if (mysqli_num_rows($res) > 0) {
                echo "
                    <table>
                        <tr>
                            <th>KTU ID</th>
                            <td>{$row['ktu_id']}</td>
                        </tr>
                        <tr>
                            <th>Series 1</th>
                            <td>{$row['series1']}</td>
                        </tr>
                        <tr>
                            <th>Series 2</th>
                            <td>{$row['series2']}</td>
                        </tr>
                        <tr>
                            <th>Assignment 1</th>
                            <td>{$row['assignment1']}</td>
                        </tr>
                        <tr>
                            <th>Assignment 2</th>
                            <td>{$row['assignment2']}</td>
                        </tr>
                        <tr>
                            <th>Attendance</th>
                            <td>{$row['attendance']}</td>
                        </tr>
                    </table>

                ";
            } else {
                echo "No marks added!";
            }
        }
        echo "
            <form method='post' action='update.php'>
                <input type='hidden' value='{$row['ktu_id']}' name='ktu_id'>
                <input name='add-update' type='submit' value='Add or Update Marks'>
            </form>
        ";
    }
?>