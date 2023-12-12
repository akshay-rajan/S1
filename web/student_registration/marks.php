<form action="" method="POST">
    Select a student: <select name="ktu_id">
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
            if (mysqli_num_rows($res) > 0) {
				echo "<table border=1>
						<tr>
							<th>Subject</th>
				            <th>Series 1</th>
							<th>Series 2</th>
	                        <th>Assignment 1</th>
	                        <th>Assignment 2</th>
	                        <th>Attendance</th>
						</tr>";
				while ($row = mysqli_fetch_assoc($res)) {
		            echo "<tr>
		                        <td>{$row['subject']}</td>
		                        <td>{$row['series1']}</td>
		                        <td>{$row['series2']}</td>
		                        <td>{$row['assignment1']}</td>
		                        <td>{$row['assignment2']}</td>
		                        <td>{$row['attendance']}</td>
		                    </tr>";
				}
				echo "</table>";
            } else {
                echo "No marks added!";
            }
        }
        echo "
            <form method='post' action='update.php'>
                <input type='hidden' value='{$ktu_id}' name='ktu_id'>
                <input name='add-update' type='submit' value='Add or Update Marks'>
            </form>
        ";
    }
?>
