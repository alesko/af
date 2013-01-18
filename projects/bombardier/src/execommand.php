<?php

echo "Hello from execommand.php<p>";
echo "The command you whated to execute was:<p>";
echo $_GET['command'];
echo "<p>";

// you define this variable here so that it exists for the call to exec
$output = null;

// Windows users: 'dir c:\\' or something similar
exec('func_pointer command', $output);
echo "<pre>" . var_export($output, TRUE) . "</pre>";

echo "<button type='button' onclick='menu.html'>Return</button><p>"

?>
