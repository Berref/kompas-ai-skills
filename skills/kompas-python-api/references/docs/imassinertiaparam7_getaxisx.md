# GetAxisX - Получить вектор направлений главных центральных осей инерции по оси X

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IMassInertiaParam7 ](imassinertiaparam7.html) > [IMassInertiaParam7 - методы ](imassinertiaparam7_methods.html) |  Scroll [ [ [ ](imassinertiaparam7_getaxisy.html "К следующему разделу")](imassinertiaparam7_methods.html "На уровень выше")](imassinertiaparam7_calculate.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imassinertiaparam7.html)

Синтаксис Automation:

BOOL GetAxisX( double * x, double * y, double * z );

Синтаксис COM:

HRESULT GetAxisX( double * x, double * y, double * z, VARIANT_BOOL * Result );

Выходные параметры:

| Координаты x, y, z точки вектора направления по оси X.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получать координаты x, y, z точки вектора направления по оси X.

Подразделы:

(отсутствуют)
