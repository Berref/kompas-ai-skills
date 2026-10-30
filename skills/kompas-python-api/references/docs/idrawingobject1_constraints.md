# Constraints - Массив SAFEARRAY ограничений для данного объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Ограничения ](bb2391397.html) > [Интерфейс IDrawingObject1 ](idrawingobject1.html) > [IDrawingObject1 - свойства ](idrawingobject1_props.html) |  Scroll [ [ [ ](constraintsstate.html "К следующему разделу")](idrawingobject1_props.html "На уровень выше")](idrawingobject1_autotransparentbackground.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawingobject1.html)

Аналоги метода в API5: экспортная функция [ksGetObjConstraints](ksgetobjconstraints.html) и метод [ksDocument2D::ksGetObjConstraints](ksdocument2d_ksgetobjconstraints.html). Тип данных:VARIANT ( VT_ARRAY|VT_DISPATCH ).

Синтаксис Automation:

Constraints = iObject.Constraints | Получить свойство([* ](1.html))  
---|---  
Constraints = iObject.GetConstraints() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Constraints = iObject->get_Constraints(&Constraints) | Получить свойство  
---|---  
  
Примечание:

Свойство позволяет получить массив SAFEARRAY ограничений для данного объекта. Это массив LPDISPATCH, который можно преобразовать в интерфейсы [IParametriticConstraint](iparametriticconstraint.html). Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
