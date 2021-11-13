
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* direccion del archivo
 * \param pArrayListEmployee LinkedList* puntero a la linkedList
 * \return int -1 si la lista esta vacia || 0 si el archivo vino en NULL ||  1 si pudo cargar
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* direccion del archivo
 * \param pArrayListEmployee LinkedList* puntero a la linkedList
 * \return int -1 si el archivo vino en NULL ||  1 si pudo cargar
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* puntero a direccion de memoria que apunta la linkedList
 * \return int -1 si la lista esta vacia || 0 si el usuario cancela el alta || 1 si pudo dar de alta
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* puntero a direccion de memoria que apunta la linkedList
 * \return int -2 si alguno de los paraametros vino en NULL || -1 si la lista esta vacia ||0 si no se
 * 			encontro el id || 2 si encontro pero el usuario cancela la modificacion || 1 si pudo modificar
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* puntero a direccion de memoria que apunta la linkedList
 * \return int -2 si alguno de los paraametros vino en NULL || -1 si la lista esta vacia ||0 si no se
 * 			encontro el id || 2 si encontro pero el usuario cancela la baja || 1 si pudo dar de baja
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* puntero a direccion de memoria que apunta la linkedList
 * \return int -2 si alguno de los parametros vino en NULL || -1 si la lista esta vacia || 0 si no pudo
 * 				mostrar || 1 si pudo mostrar
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* puntero a direccion de memoria que apunta la linkedList
 * \return int -1 si alguno de los parametros vino en NULL || 0 si la lista esta vacia || 1 si puede ordenar
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* direccion del archivo
 * \param pArrayListEmployee LinkedList* puntero a la linkedList
 * \return int -2 si alguno de los parametros vino en NULL || 2 si la lista esta vacia || -1 si el usuario
 * 				cancela el guardado de datos || 0 si el archivo vino en NULL || 1 si pudo guardar los datos
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* direccion del archivo
 * \param pArrayListEmployee LinkedList* puntero a la linkedList
 * \return int -2 si alguno de los parametros vino en NULL || -1 si la lista esta vacia || -1 si el usuario
 * 				cancela el guardado de datos || 0 si el archivo vino en NULL || 1 si pudo guardar los datos
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


