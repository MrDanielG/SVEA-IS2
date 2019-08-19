-- -----------------------------------------------------
-- Schema db_svea
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema db_svea
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `db_svea` DEFAULT CHARACTER SET utf8 ;
USE `db_svea` ;

-- -----------------------------------------------------
-- Table `db_svea`.`tipo_usuario`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `db_svea`.`tipo_usuario` (
  `id_tipo_usuario` INT NOT NULL AUTO_INCREMENT,
  `descripcion` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`id_tipo_usuario`));
-- ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `db_svea`.`usuario`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `db_svea`.`usuario` (
  `id_usuario` INT NOT NULL AUTO_INCREMENT,
  `contra_usuario` VARCHAR(45) NOT NULL,
  `correo_usuario` VARCHAR(45) NOT NULL,
  `id_tipo_usuario` INT NOT NULL,
  PRIMARY KEY (`id_usuario`),
  -- INDEX `fk_usuario_tipo_usuario_idx` (`id_tipo_usuario` ASC) VISIBLE,
  -- CONSTRAINT `fk_usuario_tipo_usuario`
    FOREIGN KEY (`id_tipo_usuario`)
    REFERENCES `db_svea`.`tipo_usuario` (`id_tipo_usuario`));
 --    ON DELETE NO ACTION
  --  ON UPDATE NO ACTION)
-- ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `db_svea`.`votante`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `db_svea`.`votante` (
  `ine` INT NOT NULL,
  `nombre_votante` VARCHAR(100) NOT NULL,
  `usuario_id_usuario` INT NOT NULL,
  PRIMARY KEY (`ine`),
  -- INDEX `fk_votante_usuario1_idx` (`usuario_id_usuario` ASC) VISIBLE,
 -- CONSTRAINT `fk_votante_usuario1`
    FOREIGN KEY (`usuario_id_usuario`)
    REFERENCES `db_svea`.`usuario` (`id_usuario`));
 --   ON DELETE NO ACTION
  --  ON UPDATE NO ACTION)
-- ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `db_svea`.`partido`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `db_svea`.`partido` (
  `id_partido` INT NOT NULL AUTO_INCREMENT,
  `nombre_partido` VARCHAR(45) NOT NULL,
  `foto_partido` VARCHAR(45) NULL,
  `usuario_id_usuario` INT NOT NULL,
  PRIMARY KEY (`id_partido`),
 -- INDEX `fk_partido_usuario1_idx` (`usuario_id_usuario` ASC) VISIBLE,
 -- CONSTRAINT `fk_partido_usuario1`
    FOREIGN KEY (`usuario_id_usuario`)
    REFERENCES `db_svea`.`usuario` (`id_usuario`));
  --  ON DELETE NO ACTION
  --  ON UPDATE NO ACTION)
-- ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `db_svea`.`estudios_candidato`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `db_svea`.`estudios_candidato` (
  `id_estudios_candidato` INT NOT NULL AUTO_INCREMENT,
  `grado_estudios` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`id_estudios_candidato`));
-- ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `db_svea`.`votacion`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `db_svea`.`votacion` (
  `id_votacion` INT NOT NULL AUTO_INCREMENT,
  `fecha_votacion` DATE NOT NULL,
  `hora_inicio` VARCHAR(45) NOT NULL,
  `hora_final` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`id_votacion`));
-- ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `db_svea`.`registro_propuestas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `db_svea`.`registro_propuestas` (
  `id_registro_propuestas` INT NOT NULL AUTO_INCREMENT,
  `fehca_inicio` DATE NOT NULL,
  `fecha_fin` DATE NOT NULL,
  PRIMARY KEY (`id_registro_propuestas`));
-- ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `db_svea`.`presentacion_propuestas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `db_svea`.`presentacion_propuestas` (
  `id_presentacion_propuestas` INT NOT NULL AUTO_INCREMENT,
  `fecha_inicio` DATE NOT NULL,
  `fecha_final` DATE NOT NULL,
  PRIMARY KEY (`id_presentacion_propuestas`));
-- ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `db_svea`.`proceso_propuestas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `db_svea`.`proceso_propuestas` (
  `id_proceso_propuestas` INT NOT NULL AUTO_INCREMENT,
  `id_registro_propuestas` INT NOT NULL,
  `id_presentacion_propuestas` INT NOT NULL,
  PRIMARY KEY (`id_proceso_propuestas`),
  -- INDEX `fk_proceso_propuestas_registro_propuestas1_idx` (`id_registro_propuestas` ASC) VISIBLE,
  -- INDEX `fk_proceso_propuestas_presentacion_propuestas1_idx` (`id_presentacion_propuestas` ASC) VISIBLE,
 -- CONSTRAINT `fk_proceso_propuestas_registro_propuestas1`
    FOREIGN KEY (`id_registro_propuestas`)
    REFERENCES `db_svea`.`registro_propuestas` (`id_registro_propuestas`),
 --   ON DELETE NO ACTION
  --  ON UPDATE NO ACTION,
--  CONSTRAINT `fk_proceso_propuestas_presentacion_propuestas1`
    FOREIGN KEY (`id_presentacion_propuestas`)
    REFERENCES `db_svea`.`presentacion_propuestas` (`id_presentacion_propuestas`));
  --  ON DELETE NO ACTION
 --   ON UPDATE NO ACTION)
-- ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `db_svea`.`proceso_electoral`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `db_svea`.`proceso_electoral` (
  `id_proceso_electoral` INT NOT NULL AUTO_INCREMENT,
  `id_votacion` INT NOT NULL,
  `id_proceso_propuestas` INT NOT NULL,
  PRIMARY KEY (`id_proceso_electoral`),
 -- INDEX `fk_proceso_electoral_votacion1_idx` (`id_votacion` ASC) VISIBLE,
--  INDEX `fk_proceso_electoral_proceso_propuestas1_idx` (`id_proceso_propuestas` ASC) VISIBLE,
 -- CONSTRAINT `fk_proceso_electoral_votacion1`
    FOREIGN KEY (`id_votacion`)
    REFERENCES `db_svea`.`votacion` (`id_votacion`),
  --  ON DELETE NO ACTION
  --  ON UPDATE NO ACTION,
 -- CONSTRAINT `fk_proceso_electoral_proceso_propuestas1`
    FOREIGN KEY (`id_proceso_propuestas`)
    REFERENCES `db_svea`.`proceso_propuestas` (`id_proceso_propuestas`));
  --  ON DELETE NO ACTION
 --  ON UPDATE NO ACTION)
-- ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `db_svea`.`candidato`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `db_svea`.`candidato` (
  `id_candidato` INT NOT NULL AUTO_INCREMENT,
  `nombre_candidato` VARCHAR(100) NOT NULL,
  `edad_candidato` INT NOT NULL,
  `informacion` VARCHAR(100) NULL,
  `foto_candidato` LONGBLOB NULL,
  `id_partido` INT NOT NULL,
  `id_estudios_candidato` INT NOT NULL,
  `id_proceso_electoral` INT NOT NULL,
  PRIMARY KEY (`id_candidato`),
  -- INDEX `fk_candidato_partido1_idx` (`id_partido` ASC) VISIBLE,
  -- INDEX `fk_candidato_estudios_candidato1_idx` (`id_estudios_candidato` ASC) VISIBLE,
 -- INDEX `fk_candidato_proceso_electoral1_idx` (`id_proceso_electoral` ASC) VISIBLE,
 -- CONSTRAINT `fk_candidato_partido1`
    FOREIGN KEY (`id_partido`)
    REFERENCES `db_svea`.`partido` (`id_partido`),
  --  ON DELETE NO ACTION
   -- ON UPDATE NO ACTION,
 -- CONSTRAINT `fk_candidato_estudios_candidato1`
    FOREIGN KEY (`id_estudios_candidato`)
    REFERENCES `db_svea`.`estudios_candidato` (`id_estudios_candidato`),
  --  ON DELETE NO ACTION
  --  ON UPDATE NO ACTION,
 -- CONSTRAINT `fk_candidato_proceso_electoral1`
    FOREIGN KEY (`id_proceso_electoral`)
    REFERENCES `db_svea`.`proceso_electoral` (`id_proceso_electoral`));
  --  ON DELETE NO ACTION
  --  ON UPDATE NO ACTION)
-- ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `db_svea`.`boleta`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `db_svea`.`boleta` (
  `id_boleta` INT NOT NULL AUTO_INCREMENT,
  `votante_ine` INT NOT NULL,
  `candidato_id_candidato` INT NOT NULL,
  `id_proceso_electoral` INT NOT NULL,
  PRIMARY KEY (`id_boleta`),
  -- INDEX `fk_boleta_votante1_idx` (`votante_ine` ASC) VISIBLE,
  -- INDEX `fk_boleta_candidato1_idx` (`candidato_id_candidato` ASC) VISIBLE,
  -- INDEX `fk_boleta_proceso_electoral1_idx` (`id_proceso_electoral` ASC) VISIBLE,
  -- CONSTRAINT `fk_boleta_votante1`
    FOREIGN KEY (`votante_ine`)
    REFERENCES `db_svea`.`votante` (`ine`),
  --  ON DELETE NO ACTION
  --  ON UPDATE NO ACTION,
 -- CONSTRAINT `fk_boleta_candidato1`
    FOREIGN KEY (`candidato_id_candidato`)
    REFERENCES `db_svea`.`candidato` (`id_candidato`),
  --  ON DELETE NO ACTION
  --  ON UPDATE NO ACTION,
 -- CONSTRAINT `fk_boleta_proceso_electoral1`
    FOREIGN KEY (`id_proceso_electoral`)
    REFERENCES `db_svea`.`proceso_electoral` (`id_proceso_electoral`));
  --  ON DELETE NO ACTION
  --  ON UPDATE NO ACTION)
-- ENGINE = InnoDB;