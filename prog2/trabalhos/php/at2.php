<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
	<?php
		$alunos = array(
			array("nome" => "joao", "np1" => 7,"np2" => 5),
			array("nome" => "pedro", "np1" => 6,"np2" => 7),
			array("nome" => "maria", "np1" => 7,"np2" => 7),
			array("nome" => "jose", "np1" => 9,"np2" => 8),
			array("nome" => "ricardo", "np1" => 3,"np2" => 8),
			array("nome" => "ana", "np1" => 5,"np2" => 6),
			array("nome" => "guilherme", "np1" => 8,"np2" => 7),
			array("nome" => "renata", "np1" => 8,"np2" => 6),
			array("nome" => "juliana", "np1" => 6,"np2" => 8),
			array("nome" => "sara", "np1" => 5,"np2" => 4)
		);
		foreach ($alunos as $item) {
			echo "<div>
					<p><strong>$item[0]</strong></p>
					<p>$item[1]</p>
					<p>$item[2]</p>";
			echo "</p></div>";
		}
	?>
</body>
</html>
