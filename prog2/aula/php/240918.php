<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>exemplo</title>
</head>
<body>
	<?php
		$produto = "fone de ouvido";

		$opinioes = array(
			array("joao", "gostei muito", 5),
			array("pedro", "bom mais pode melhorar", 3),
			array("luiza", "achei muito fraquinho", 1),
			array("marta", "otimo", 5)
		);

		echo "<h1>$produto</h1>";	//as aspas duplas são usadas para que a variavel seja substituida pelo seu valor

		foreach ($opinioes as $item) {
			echo "<div>
					<p><strong>$item[0]</strong></p>
					<p>$item[1]</p>";
			for ($i=0; $i < $item[2]; $i++) { 
				echo "&circledast;";
			}
			echo "</p></div>";
		}

		echo "<pre>";	//formata a exibição do print_r
		print_r($opinioes); //imprime todos os elementos do array de uma só vez
		echo "</pre>";

		
	?>
</body>
</html>