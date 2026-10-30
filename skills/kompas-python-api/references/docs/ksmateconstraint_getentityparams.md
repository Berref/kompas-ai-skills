# GetEntityParams - Получить параметры математических обектов, участвующих в сопряжении

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [Массив сопряжений (Интерфейсы ksMateConstraintCollection, IMateConstraintCollection) ](ksmateconstraintcollection.html) > [Интерфейсы структуры параметров сопряжения (Интерфейсы ksMateConstraint, IMateConstraint) ](ksmateconstraint.html) > [IMateConstraint - методы ](ksmateconstraint_methods.html) |  Scroll [ [ [ ](ksmateconstraint_getfeature.html "К следующему разделу")](ksmateconstraint_methods.html "На уровень выше")](ksmateconstraint_getbaseobj.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmateconstraint.html)

Синтаксис Automation:

long GetEntityParams (long index, VARIANT * params);

Синтаксис COM:

int GetEntityParams (int index, VARIANT * params);

Входные параметры:

index | \- индекс объекта.  
---|---  
  
Выходные параметры Automation:

params | \- параметры объекта массив SafeArray вещественных чисел.  
---|---  
  
Выходные параметры COM:

params | \- параметры объекта.  
---|---  
  
Возвращаемое значение:

тип математического объекта, участвующего в сопряжении из [ksMateType](ksmatetype.html) | \- если параметры получены,  
---|---  
ksMateUnknown | \- в случае ошибки.  
  
Примечание:

1\. Параметры возвращаются в системе координат сборки. При необходимости их можно перевести в систему координат нужного компонента с помощью функции [IPart::TransformPoint](kspart_transformpoint.html).

2\. Геометрический объект для сопряжения описывается набором из 8-ми вещественных чисел, сгруппированных следующим образом:

•три координаты точки Pc, Pc = { pointX, pointY, pointZ },

•три координаты вектора V, V = { vectorI, vectorJ, vectorK },

•две координаты, соответствующие радиусам, V = { vectorI, vectorJ, vectorK }.

[Представление математических объектов, участвующих в сопряжении...](matetype_intro.html)

Подразделы:

(отсутствуют)
