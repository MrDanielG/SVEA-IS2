-- phpMyAdmin SQL Dump
-- version 4.8.2
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 21-08-2019 a las 05:02:53
-- Versión del servidor: 10.1.34-MariaDB
-- Versión de PHP: 7.2.7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `db_svea`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `boleta`
--

CREATE TABLE `boleta` (
  `id_boleta` int(11) NOT NULL,
  `votante_ine` int(11) NOT NULL,
  `candidato_id_candidato` int(11) NOT NULL,
  `id_proceso_electoral` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `candidato`
--

CREATE TABLE `candidato` (
  `id_candidato` int(11) NOT NULL,
  `nombre_candidato` varchar(100) NOT NULL,
  `edad_candidato` int(11) NOT NULL,
  `informacion` varchar(100) DEFAULT NULL,
  `id_partido` int(11) NOT NULL,
  `id_estudios_candidato` int(11) NOT NULL,
  `id_proceso_electoral` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `estudios_candidato`
--

CREATE TABLE `estudios_candidato` (
  `id_estudios_candidato` int(11) NOT NULL,
  `grado_estudios` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `partido`
--

CREATE TABLE `partido` (
  `id_partido` int(11) NOT NULL,
  `nombre_partido` varchar(45) NOT NULL,
  `foto_partido` varchar(100) DEFAULT NULL,
  `usuario_id_usuario` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `partido`
--

INSERT INTO `partido` (`id_partido`, `nombre_partido`, `foto_partido`, `usuario_id_usuario`) VALUES
(1, 'PAN', 'D:/bd_svea/panlogo.png', NULL);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `presentacion_propuestas`
--

CREATE TABLE `presentacion_propuestas` (
  `id_presentacion_propuestas` int(11) NOT NULL,
  `fecha_inicio` date NOT NULL,
  `fecha_final` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `proceso_electoral`
--

CREATE TABLE `proceso_electoral` (
  `id_proceso_electoral` int(11) NOT NULL,
  `id_votacion` int(11) NOT NULL,
  `id_proceso_propuestas` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `proceso_propuestas`
--

CREATE TABLE `proceso_propuestas` (
  `id_proceso_propuestas` int(11) NOT NULL,
  `id_registro_propuestas` int(11) NOT NULL,
  `id_presentacion_propuestas` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `propuesta`
--

CREATE TABLE `propuesta` (
  `id_propuesta` int(11) NOT NULL,
  `contenido` varchar(500) NOT NULL,
  `beneficios` varchar(500) DEFAULT NULL,
  `validada` tinyint(4) NOT NULL,
  `candidato_id_candidato` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `registro_propuestas`
--

CREATE TABLE `registro_propuestas` (
  `id_registro_propuestas` int(11) NOT NULL,
  `fehca_inicio` date NOT NULL,
  `fecha_fin` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tipo_usuario`
--

CREATE TABLE `tipo_usuario` (
  `id_tipo_usuario` int(11) NOT NULL,
  `descripcion` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `tipo_usuario`
--

INSERT INTO `tipo_usuario` (`id_tipo_usuario`, `descripcion`) VALUES
(1, 'Administrador'),
(2, 'Partido'),
(3, 'Votante');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usuario`
--

CREATE TABLE `usuario` (
  `id_usuario` int(11) NOT NULL,
  `contra_usuario` varchar(45) NOT NULL,
  `correo_usuario` varchar(45) NOT NULL,
  `id_tipo_usuario` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `usuario`
--

INSERT INTO `usuario` (`id_usuario`, `contra_usuario`, `correo_usuario`, `id_tipo_usuario`) VALUES
(1, 'admin', 'admin@admin.com', 1),
(2, 'partido', 'partido@partido.com', 2),
(3, 'votante', 'votante@votante.com', 3);

-- --------------------------------------------------------

--
-- Estructura Stand-in para la vista `vista_partidos`
-- (Véase abajo para la vista actual)
--
CREATE TABLE `vista_partidos` (
`id_partido` int(11)
,`nombre_partido` varchar(45)
);

-- --------------------------------------------------------

--
-- Estructura Stand-in para la vista `vista_propuesta`
-- (Véase abajo para la vista actual)
--
CREATE TABLE `vista_propuesta` (
`id_propuesta` int(11)
,`nombre_candidato` varchar(100)
,`nombre_partido` varchar(45)
,`contenido` varchar(500)
,`beneficios` varchar(500)
,`validada` tinyint(4)
);

-- --------------------------------------------------------

--
-- Estructura Stand-in para la vista `vista_votantes`
-- (Véase abajo para la vista actual)
--
CREATE TABLE `vista_votantes` (
`ine` int(11)
,`nombre_votante` varchar(100)
);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `votacion`
--

CREATE TABLE `votacion` (
  `id_votacion` int(11) NOT NULL,
  `fecha_votacion` date NOT NULL,
  `hora_inicio` varchar(45) NOT NULL,
  `hora_final` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `votante`
--

CREATE TABLE `votante` (
  `ine` int(11) NOT NULL,
  `nombre_votante` varchar(100) NOT NULL,
  `usuario_id_usuario` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `votante`
--

INSERT INTO `votante` (`ine`, `nombre_votante`, `usuario_id_usuario`) VALUES
(12, 'MARTÍN COBA PULIDO', 3),
(123, 'DANIEL GARNICA SÁNCHEZ', NULL);

-- --------------------------------------------------------

--
-- Estructura Stand-in para la vista `voto`
-- (Véase abajo para la vista actual)
--
CREATE TABLE `voto` (
`foto_partido` varchar(100)
,`nombre_candidato` varchar(100)
,`nombre_partido` varchar(45)
);

-- --------------------------------------------------------

--
-- Estructura para la vista `vista_partidos`
--
DROP TABLE IF EXISTS `vista_partidos`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `vista_partidos`  AS  select `partido`.`id_partido` AS `id_partido`,`partido`.`nombre_partido` AS `nombre_partido` from `partido` where isnull(`partido`.`usuario_id_usuario`) ;

-- --------------------------------------------------------

--
-- Estructura para la vista `vista_propuesta`
--
DROP TABLE IF EXISTS `vista_propuesta`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `vista_propuesta`  AS  select `p`.`id_propuesta` AS `id_propuesta`,`c`.`nombre_candidato` AS `nombre_candidato`,`pa`.`nombre_partido` AS `nombre_partido`,`p`.`contenido` AS `contenido`,`p`.`beneficios` AS `beneficios`,`p`.`validada` AS `validada` from ((`propuesta` `p` join `candidato` `c` on((`p`.`candidato_id_candidato` = `c`.`id_candidato`))) join `partido` `pa` on((`pa`.`id_partido` = `c`.`id_partido`))) ;

-- --------------------------------------------------------

--
-- Estructura para la vista `vista_votantes`
--
DROP TABLE IF EXISTS `vista_votantes`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `vista_votantes`  AS  select `votante`.`ine` AS `ine`,`votante`.`nombre_votante` AS `nombre_votante` from `votante` where isnull(`votante`.`usuario_id_usuario`) ;

-- --------------------------------------------------------

--
-- Estructura para la vista `voto`
--
DROP TABLE IF EXISTS `voto`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `voto`  AS  select `pa`.`foto_partido` AS `foto_partido`,`c`.`nombre_candidato` AS `nombre_candidato`,`pa`.`nombre_partido` AS `nombre_partido` from (`candidato` `c` join `partido` `pa` on((`pa`.`id_partido` = `c`.`id_partido`))) ;

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `boleta`
--
ALTER TABLE `boleta`
  ADD PRIMARY KEY (`id_boleta`),
  ADD KEY `votante_ine` (`votante_ine`),
  ADD KEY `candidato_id_candidato` (`candidato_id_candidato`),
  ADD KEY `id_proceso_electoral` (`id_proceso_electoral`);

--
-- Indices de la tabla `candidato`
--
ALTER TABLE `candidato`
  ADD PRIMARY KEY (`id_candidato`),
  ADD KEY `id_partido` (`id_partido`),
  ADD KEY `id_estudios_candidato` (`id_estudios_candidato`),
  ADD KEY `id_proceso_electoral` (`id_proceso_electoral`);

--
-- Indices de la tabla `estudios_candidato`
--
ALTER TABLE `estudios_candidato`
  ADD PRIMARY KEY (`id_estudios_candidato`);

--
-- Indices de la tabla `partido`
--
ALTER TABLE `partido`
  ADD PRIMARY KEY (`id_partido`),
  ADD KEY `usuario_id_usuario` (`usuario_id_usuario`);

--
-- Indices de la tabla `presentacion_propuestas`
--
ALTER TABLE `presentacion_propuestas`
  ADD PRIMARY KEY (`id_presentacion_propuestas`);

--
-- Indices de la tabla `proceso_electoral`
--
ALTER TABLE `proceso_electoral`
  ADD PRIMARY KEY (`id_proceso_electoral`),
  ADD KEY `id_votacion` (`id_votacion`),
  ADD KEY `id_proceso_propuestas` (`id_proceso_propuestas`);

--
-- Indices de la tabla `proceso_propuestas`
--
ALTER TABLE `proceso_propuestas`
  ADD PRIMARY KEY (`id_proceso_propuestas`),
  ADD KEY `id_registro_propuestas` (`id_registro_propuestas`),
  ADD KEY `id_presentacion_propuestas` (`id_presentacion_propuestas`);

--
-- Indices de la tabla `propuesta`
--
ALTER TABLE `propuesta`
  ADD PRIMARY KEY (`id_propuesta`),
  ADD KEY `candidato_id_candidato` (`candidato_id_candidato`);

--
-- Indices de la tabla `registro_propuestas`
--
ALTER TABLE `registro_propuestas`
  ADD PRIMARY KEY (`id_registro_propuestas`);

--
-- Indices de la tabla `tipo_usuario`
--
ALTER TABLE `tipo_usuario`
  ADD PRIMARY KEY (`id_tipo_usuario`);

--
-- Indices de la tabla `usuario`
--
ALTER TABLE `usuario`
  ADD PRIMARY KEY (`id_usuario`),
  ADD KEY `id_tipo_usuario` (`id_tipo_usuario`);

--
-- Indices de la tabla `votacion`
--
ALTER TABLE `votacion`
  ADD PRIMARY KEY (`id_votacion`);

--
-- Indices de la tabla `votante`
--
ALTER TABLE `votante`
  ADD PRIMARY KEY (`ine`),
  ADD KEY `usuario_id_usuario` (`usuario_id_usuario`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `boleta`
--
ALTER TABLE `boleta`
  MODIFY `id_boleta` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `candidato`
--
ALTER TABLE `candidato`
  MODIFY `id_candidato` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `estudios_candidato`
--
ALTER TABLE `estudios_candidato`
  MODIFY `id_estudios_candidato` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `partido`
--
ALTER TABLE `partido`
  MODIFY `id_partido` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT de la tabla `presentacion_propuestas`
--
ALTER TABLE `presentacion_propuestas`
  MODIFY `id_presentacion_propuestas` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `proceso_electoral`
--
ALTER TABLE `proceso_electoral`
  MODIFY `id_proceso_electoral` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `proceso_propuestas`
--
ALTER TABLE `proceso_propuestas`
  MODIFY `id_proceso_propuestas` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `registro_propuestas`
--
ALTER TABLE `registro_propuestas`
  MODIFY `id_registro_propuestas` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `tipo_usuario`
--
ALTER TABLE `tipo_usuario`
  MODIFY `id_tipo_usuario` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT de la tabla `usuario`
--
ALTER TABLE `usuario`
  MODIFY `id_usuario` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT de la tabla `votacion`
--
ALTER TABLE `votacion`
  MODIFY `id_votacion` int(11) NOT NULL AUTO_INCREMENT;


--
-- AUTO_INCREMENT de la tabla `propuesta`
--
ALTER TABLE `propuesta`
  MODIFY `id_propuesta` int(11) NOT NULL AUTO_INCREMENT;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `boleta`
--
ALTER TABLE `boleta`
  ADD CONSTRAINT `boleta_ibfk_1` FOREIGN KEY (`votante_ine`) REFERENCES `votante` (`ine`),
  ADD CONSTRAINT `boleta_ibfk_2` FOREIGN KEY (`candidato_id_candidato`) REFERENCES `candidato` (`id_candidato`),
  ADD CONSTRAINT `boleta_ibfk_3` FOREIGN KEY (`id_proceso_electoral`) REFERENCES `proceso_electoral` (`id_proceso_electoral`);

--
-- Filtros para la tabla `candidato`
--
ALTER TABLE `candidato`
  ADD CONSTRAINT `candidato_ibfk_1` FOREIGN KEY (`id_partido`) REFERENCES `partido` (`id_partido`),
  ADD CONSTRAINT `candidato_ibfk_2` FOREIGN KEY (`id_estudios_candidato`) REFERENCES `estudios_candidato` (`id_estudios_candidato`),
  ADD CONSTRAINT `candidato_ibfk_3` FOREIGN KEY (`id_proceso_electoral`) REFERENCES `proceso_electoral` (`id_proceso_electoral`);

--
-- Filtros para la tabla `partido`
--
ALTER TABLE `partido`
  ADD CONSTRAINT `partido_ibfk_1` FOREIGN KEY (`usuario_id_usuario`) REFERENCES `usuario` (`id_usuario`);

--
-- Filtros para la tabla `proceso_electoral`
--
ALTER TABLE `proceso_electoral`
  ADD CONSTRAINT `proceso_electoral_ibfk_1` FOREIGN KEY (`id_votacion`) REFERENCES `votacion` (`id_votacion`),
  ADD CONSTRAINT `proceso_electoral_ibfk_2` FOREIGN KEY (`id_proceso_propuestas`) REFERENCES `proceso_propuestas` (`id_proceso_propuestas`);

--
-- Filtros para la tabla `proceso_propuestas`
--
ALTER TABLE `proceso_propuestas`
  ADD CONSTRAINT `proceso_propuestas_ibfk_1` FOREIGN KEY (`id_registro_propuestas`) REFERENCES `registro_propuestas` (`id_registro_propuestas`),
  ADD CONSTRAINT `proceso_propuestas_ibfk_2` FOREIGN KEY (`id_presentacion_propuestas`) REFERENCES `presentacion_propuestas` (`id_presentacion_propuestas`);

--
-- Filtros para la tabla `propuesta`
--
ALTER TABLE `propuesta`
  ADD CONSTRAINT `propuesta_ibfk_1` FOREIGN KEY (`candidato_id_candidato`) REFERENCES `candidato` (`id_candidato`);

--
-- Filtros para la tabla `usuario`
--
ALTER TABLE `usuario`
  ADD CONSTRAINT `usuario_ibfk_1` FOREIGN KEY (`id_tipo_usuario`) REFERENCES `tipo_usuario` (`id_tipo_usuario`);

--
-- Filtros para la tabla `votante`
--
ALTER TABLE `votante`
  ADD CONSTRAINT `votante_ibfk_1` FOREIGN KEY (`usuario_id_usuario`) REFERENCES `usuario` (`id_usuario`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
