# ksSetMacroParam - Записать параметры макроэлемента

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Составные объекты ](bt1730612.html) |  Scroll [ [ [ ](ksdocument2d_kssetmacroplacement.html "К следующему разделу")](bt1730612.html "На уровень выше")](ksdocument2d_ksgetmacroplacementex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksSetMacroParam](kssetmacroparam.html)

Синтаксис Automation:

long ksSetMacroParam (long ref,

LPDISPATCH userPars,

bool dblClickOff,

bool hotpoints,

bool externEdit );

Входные параметры:

ref | \- указатель на макроэлемент,  
---|---  
userPars | \- указатель на интерфейс [ksUserParam](ksuserparam.html),  
dblClickOff | \- признак редактирования по двойному щелчку: TRUE - выключено, FALSE - включено,  
hotpoints | \- признак наличия интерфейса характерных точек: TRUE - интерфейс характерных точек включен, FALSE - выключен,  
externEdit | признак наличия интерфейса внешнего управления: TRUE - интерфейс внешнего управления включен, FALSE - выключен.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Метод записывает в указанный макроэлемент параметры редактирования: имя файла библиотеки, имя библиотеки и номер функции, предназначенной для редактирования данного макроэлемента. Получить значения параметров макроэлемента можно, используя метод [ksDocument2D::ksGetMacroParam](ksdocument2d_ksgetmacroparam.html).

2\. При необходимости в параметрах макроэлемента можно дополнительно сохранить пользовательские данные (допустимы все типы данных, кроме указателей), задав [ksUserParam::userParams](ksuserparam_userparams.html) или [ksUserParam::SetUserArray](ksuserparam_setuserarray.html).

3\. При значениях параметров [ksUserParam::fileName](ksuserparam_filename.html) = 0, [ksUserParam::libName](ksuserparam_libname.html) = 0, [ksUserParam::number](ksuserparam_number.html)=-1 в макроэлементе сохраняется в качестве редактирующей та функция, которая вызвала метод ksSetMacroParam.

4\. При обработке событий это правило не действует и в макро прописываются имя той библиотеки и ее файла, которая была использована непосредственно перед этим событием. Поэтому при создании макроэлемент по событию необходимо явно задавать имя библиотеки, имя файла и номер функции.

Подразделы:

(отсутствуют)
