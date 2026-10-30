# Пример использования функций работы со слоями

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void Layers_Example (void) {

reference lay1, lay2;

int number;

char buf[128];

LayerParam par;

lay1 = Layer (1); /* создание слоя 1 */

strcpy(par.name, Квадрат);

par.state = 0; par.color = RGB(255, 0, 0); /* красный */

SetObjParam (lay1,&par,sizeof(par), ALLPARAM);

LineSeg (0, 0, 0, 100, 1); /* объекты записываются */

LineSeg (0, 100, 100, 100, 1); /* в слой 1 - Квадрат */

LineSeg (100, 100, 100, 0, 1);

LineSeg (100, 0, 0, 0, 1);

lay2 = Layer (2); /* создание слоя 2 */

strcpy(par.name, Треугольник);

par.state = 0; par.color = RGB(0, 255, 0); /* зеленый */

SetObjParam (lay2,&par,sizeof(par), ALLPARAM);

LineSeg (10, 10, 50, 90, 2); /* объекты записываются */

LineSeg (50, 90, 90, 10, 2); /* в слой Треугольник */

LineSeg (90, 10, 10, 10, 2);

number = GetLayerNumber (lay1); /* получить номер 1*/

sprintf(buf,number=%d,number);

Message(buf);

lay2 = GetLayerReference(2); /* получить указатель на слой с номером 2 */

}; /* Layers_Example */
