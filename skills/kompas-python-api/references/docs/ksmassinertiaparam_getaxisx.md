# GetAxisX, GetAxisY, GetAxisZ - Получить вектора направлений главных центральных осей инерции

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Трехмерное тело ](ca1747705.html) > [МЦХ тела вращения или выдавливания (Интерфейсы ksMassInertiaParam, IMassInertiaParam) ](ksmassinertiaparam.html) > [IMassInertiaParam - методы ](ksmassinertiaparam_methods.html) |  Scroll [ [ [ ](ksmassinertiaparam_setbitvectorvalue.html "К следующему разделу")](ksmassinertiaparam_methods.html "На уровень выше")](ksmassinertiaparam_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmassinertiaparam.html)

Синтаксис Automation:

BOOL GetAxisX( double *x, double *y, double *z );

BOOL GetAxisY( double *x, double *y, double *z );

BOOL GetAxisZ( double *x, double *y, double *z );

Синтаксис COM:

BOOL GetAxisX( double *x, double *y, double *z);

BOOL GetAxisY( double *x, double *y, double *z);

BOOL GetAxisZ( double *x, double *y, double *z);

Выходные параметры:

x, y, z | \- вектор направления.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод применим только для трехмерных объектов.

Подразделы:

(отсутствуют)
