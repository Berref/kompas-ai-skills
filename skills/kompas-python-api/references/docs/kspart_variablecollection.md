# VariableCollection - Получить указатель на интерфейс массива внешних переменных

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_update.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_transformpoints.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

LPDISPATCH VariableCollection();

Синтаксис COM:

LPVARIABLECOLLECTION VariableCollection();

Возвращаемое значение:

| \- указатель на интерфейс ksVariableCollection или [IVariableCollection](ksvariablecollection.html).  
---|---  
  
Примечание:

Изменения в полученном массиве не отображаются в модели немедленно. Чтобы изменения вступили в силу, необходимо вызвать метод [RebuildModel](kspart_rebuildmodel.html).

Подразделы:

(отсутствуют)
