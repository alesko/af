<?php include("header.html"); ?>

<?php
$formatted = "";

//echo "Hello from execommand.php<p>";
//echo "The command you whated to execute was:<p>";
echo $_GET['command'];
//echo "<p>";

// you define this variable here so that it exists for the call to exec
$output = null;

// Windows users: 'dir c:\\' or something similar
//exec('func_pointer command', $output);
$output = array();
exec('func_pointer command', $output );
echo "<pre>";
print_r($output,true);
echo "</pre>";

$response = array();
exec('whoami', $response);
print_r($response,true);

//foreach($output as $line) {
		// append each line, but make it HTML-friendly first
//		$formatted .= htmlspecialchars($line) . "\n";
//}

//echo $output;
//print_r($output);
//echo "<pre>" $output "</pre>";

//echo "<button type='button' onclick='menu.html'>Return</button><p>"
//=======
//echo "<button type='button' onclick='location.href=";
//echo '"menu.html"';
//echo "'>Return</button><p>";
//>>>>>>> c430adc88a4db798a510623fd874c3705c2498f5

?>

<?php include("footer.html"); ?>