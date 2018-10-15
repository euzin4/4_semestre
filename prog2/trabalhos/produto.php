<?php
include "includes/cabecalho.php";
?>

	<!-- area central com 3 colunas -->
	<div class="container">
		<?php
		include "includes/menu_lateral.php";
		?>		

		<section class="col-2">
			<?php
			include "includes/conexao.php";
			$id = $_GET['id'];
			$sql = "select id, nome, imagem, descricao, valor, desconto from produto where id = $id";
			$resultado = mysqli_query($conexao, $sql);
			$produto = mysqli_fetch_array($resultado);
			if(isset($_GET['secao'])){
				$categoriaSelecionada = $_GET['secao'];
				$titulo = $CATEGORIAS[$categoriaSelecionada];
			}
			elseif(isset($_GET['busca'])){
				$titulo = "Resultado da busca por \"{$_GET['busca']}\" ";
			}
			else{
				$titulo = $produto['nome'];
			}
			?>
			<h2><?=$titulo?></h2>

			<!-- container de produtos -->
			<div class="lista-produtos">
				<!-- um produto -->
				<?php
				include "includes/functions.php";
				if(isset($categoriaSelecionada))
					$sql.= " where $categoriaSelecionada IS TRUE";
				elseif(isset($_GET['busca']))
					$sql.=" where nome like '%{$_GET['busca']}%'";
				else
					$sql.= " order by id desc limit 10"; // novidades

				//echo $sql;

				$resultado = mysqli_query($conexao, $sql);
				if(mysqli_num_rows($resultado) == 0){
					echo "<p>Nenhum produto encontrado</p>";
				}
				else{
					$produto = mysqli_fetch_array($resultado);
					?>
				    <div class="pagProduto">
				    	<div>
							<img id="imagemProd" src="img/produtos/<?=mostraImagem($produto['imagem']);?>" alt="<?=$produto['nome'];?>">
						</div>
						<div id="col-p">
							<span class="preco">
								<h2>Preço</h2>
								<?=mostraPreco($produto['valor'], $produto['desconto']);?>			
							</span>
							<br>
							<form action="adiciona.php" method="GET">
								<label for="prodId"></label>
								<input style="display: none;" type="text" name="id" value="<?=$id?>">
								<label for="quantidade">Quantidade:</label>
								<input style="width: 50px" type="number" id="quantidade" name="quantidade" value="1" min="1">
								<br>
								<input type="submit">
							</form>
						</div>
						<div id="desc">
							<p>Descrição: <?=$produto['descricao'];?></p>
						</div>
				    </div> 
				    <?php						
				}
				?>
			</div>			
		</section>
	<?php
	include "includes/mais_pedidos.php";
	?>
	</div>
	<!-- fim area central -->
<?php
include "includes/rodape.php";
?>
