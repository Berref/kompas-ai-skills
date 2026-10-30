# SetLink - Установить ссылку на переменную

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [Массив переменных (Интерфейсы ksVariableCollection, IVariableCollection) ](ksvariablecollection.html) > [Внешняя переменная (Интерфейсы ksVariable, IVariable) ](ksvariable.html) > [IVariable - методы ](ksvariable_methods.html) |  Scroll [ [ [ ](ksattribute3dcollection.html "К следующему разделу")](ksvariable_methods.html "На уровень выше")](ksvariable_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс…](ksvariable.html)

Синтаксис Automation:

BOOL SetLink (BSTR doc,BSTR name);

Синтаксис COM:

BOOL SetLink (LPOLESTR doc,LPOLESTR name);

Входные параметры:

Name | \- имя переменной, на которую будет сделана ссылка,  
---|---  
Doc | \- полный путь к документу, в котором лежит переменная с именем name.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Чтобы удалить установленную ссылку, необходимо задать следующие значения параметров:

name = NULL,

doc = NULL.

Подразделы:

(отсутствуют)
