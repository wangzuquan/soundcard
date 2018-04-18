<?php
$log_file = 'sound_log.txt';
$data = $_POST['data'];
$today = date("Y-m-d H:i:s");
$str = $today.', '.$data."\n";

if(file_exists($log_file)){
	$fp=fopen($log_file,"a"); // the file is opened as append mode
	fwrite($fp, $str);
	fclose($fp);
}else{        // the file dosen't exsit, so open a new one.
	$fp = fopen($log_file,"w");
	fwrite($fp, $str);
	fclose($fp);
}
echo "Data is stored\n"
?>	 
