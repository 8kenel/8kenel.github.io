<?php
    require_once('../model/connection.php');

    $id = (isset($_GET["id"]) && $_GET["id"] > 0) ? $_GET["id"] : "";

    $response["erro"] = false;
    $response["dados"] = null;
    $response["msgErro"] = "";
    $response["msgSucesso"] = "";
    
    try {
        $sql = "SELECT * FROM filmes_assistidos WHERE id = ?";
        $stmt = $connection -> prepare($sql);
        $stmt -> bindParam (1, $id);
        $stmt -> execute();
        $result = $stmt -> fetchAll(PDO::FETCH_ASSOC);
        $response["dados"] = $result[0];
        $response["msgSucesso"] = "Filmes de id $id retornado com sucesso!";
    } catch(PDOException $e) {
        $response ["erro"] = true;
        $response ["msgErro"] = "Erro ao retornar filme: ".$e -> getMessage();
    } finally {
        echo json_encode($response);
        exit();
    } 
?>