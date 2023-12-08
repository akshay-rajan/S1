<h1>Search Results</h1>
<?php 
    $conn = mysqli_connect('localhost', 'root', '', 'registration');
    if (!$conn) {
        echo "Cannot connect";
    } else {

        // Fetch the student's name and internal mark using JOIN
        $ktu_id = $_POST['ktu_id'];

        $sql = "SELECT * FROM users JOIN marks ON users.ktu_id = marks.ktu_id WHERE users.ktu_id = '$ktu_id'";
        $result = mysqli_query($conn, $sql);
        if (!$result) {
            echo "Cannot search!";
        } else {
            if (mysqli_num_rows($result) > 0) {

                $row = mysqli_fetch_assoc($result);

                // Calculate Internal Marks
                $series = ($row['series1'] + $row['series2']) / 5;
                $assignment = ($row['assignment1'] + $row['assignment2']) / 2;
                $attendance_percentage = $row['attendance'];
                if ($attendance_percentage >= 90) {
                    $attendance = 8;
                } else if ($attendance_percentage >= 80) {
                    $attendance = 7;
                } else if ($attendance_percentage >= 75) {
                    $attendance = 6;
                } else {
                    $attendance = 0;
                }
                $internal = $series + $assignment + $attendance;
                echo "
                    <table border=1 width='100%'>
                        <tr>
                            <th>KTU ID</th>
                            <th>NAME</th>
                            <th>INTERNAL MARKS</th>
                        </tr>
                            <td>{$row['ktu_id']}</td>
                            <td>{$row['name']}</td>
                            <td>{$internal}</td>
                    </table>
                ";

            } else {
                echo "No Student Found!";
            }
        }

    }
?>