# CreateSheetView, OpenView пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void OpenView_Example (void)

{

reference view;

int n;

ViewParam *par

par->x=100; par->y=200; par->scale=1; par->ang=0; par.state=0;

CreateSheetView(par,1); /* создать вид 1 */

LineSeg (0, 0, 0, 100, 1); /* объекты записываются */

LineSeg (0, 100, 100, 100, 1); /* в вид 1 */

LineSeg (100, 100, 100, 0, 1);

LineSeg (100, 0, 0, 0, 1);

par->x=300; par->y=200; par->scale=1; par->ang=0; par.state=0;

CreateSheetView(par,2); /* создать вид 2 */

Circle (50, 50, 20, 2); /* объект записывается в вид 2 */

OpenView(1); /* открыть вид 1 */

};
