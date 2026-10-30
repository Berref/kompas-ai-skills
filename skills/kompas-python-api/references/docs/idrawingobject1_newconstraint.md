# NewConstraint - Создать новое ограничение

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Ограничения ](bb2391397.html) > [Интерфейс IDrawingObject1 ](idrawingobject1.html) > [IDrawingObject1 - методы ](idrawingobject1_methods.html) |  Scroll [ [ [ ](bb2370796.html "К следующему разделу")](idrawingobject1_methods.html "На уровень выше")](idrawingobject1_gethyperlinkparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawingobject1.html)

Синтаксис Automation:

LPDISPATCH NewConstraint();

Синтаксис COM:

HRESULT NewConstraint([out, retval] IParametriticConstraint** Result);

Возвращаемое значение:

указатель на интерфейс [IParametriticConstraint](iparametriticconstraint.html) параметрического ограничения

Примечание:

Метод создает новое параметрическое ограничение. Для изменения параметров ограничения, необходимо задать его свойства. Ограничение появится в модели и вступит в силу после вызова метода [IParametriticConstraint::Create](iparametriticconstraint_create.html).

Подразделы:

(отсутствуют)
