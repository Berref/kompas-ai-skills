#ifndef __LIBTOOL_H
#include <libtool.h>
#endif

#include "PropManager\CPropMen.h"
#include <libhppar.h>


#if !defined(_IFUNC)
# define _IFUNC STDMETHODCALLTYPE
#endif

//-------------------------------------------------------------------------------
// Класс Отверстие
// ---
class Orifice : public PropertyManagerObject
              , public ILibPropertyObject
{
private:
  int                              m_refCount;
  ksAPI7::IProcess3DPtr            m_process3D;
protected:
  double                           m_diameter;         // Диаметр отверстия
  ksAPI7::IModelObjectPtr          m_face1;          // Первая грань
  ksAPI7::IModelObjectPtr          m_face2;          // Вторая грань
  ksAPI7::IMacroObject3DPtr        m_macroObject;    // Макрообъект
  ksAPI7::IUserDataStoragePtr      m_params;         // Параметры макрообъекта
  _bstr_t                          m_varName;        //                
public:
  Orifice(bool forProp = false);  // Конструктор
                   // Записать параметры в хранилище
  virtual                ~Orifice() { ASSERT(!m_refCount); }

  /* IUnknown */
  virtual unsigned long _IFUNC AddRef();
  virtual unsigned long _IFUNC Release();
  virtual HRESULT				_IFUNC QueryInterface(const GUID far& iid, void far*far* iface);
  virtual HRESULT       _IFUNC LtQueryInterface(int idType, void far*far* iface);

  void                   SetUserData();
  // Получить параметры макрообъекта из хранилища
  void                   GetUserData();

  virtual  void          Create(bool forProp);                       // Создание отверстия
  virtual  void          EndProcess(); // Завершить процесс редактирования
  virtual  BOOL          ProcessRun();

  _bstr_t                CreateVariable(reference c);
  bool                   UpdateVariable(ksAPI7::IModelObjectPtr sketch);

  // ILibPropertyObject  - Окно свойств
  // Имя группы объектов по умолчанию макроэлементы
  virtual LPOLESTR _IFUNC GetGroupName();
  // Добавить свойство в список свойств
  virtual BOOL     _IFUNC GetProperty(int index, PropertyParam * param);
  // Обновить параметры свойства
  virtual BOOL     _IFUNC UpdateProperty(PropertyParam * param);
  // Изменить свойство
  virtual int     _IFUNC ApplyProperty(PropertyParam * param);
  // Событие запуска внешнего редактирования для пользовательского свойсва /*ksOPControlExternalEdit*/  
  virtual BOOL     _IFUNC OnChoiceProperty(PropertyParam * param) { return FALSE; }
  // Обновить параметры свойства
  virtual BOOL     _IFUNC EndEditProperty() { return TRUE; }
  // Запрос параметров точек для визуального определения места применения параметра
  virtual BOOL     _IFUNC GetMouseEnterLeavePoint( int propertyId, long pointIndex, LPUNKNOWN parameters ) { return FALSE; }
  // Выдать идентификатор свойства по индексу
  virtual int             GetPropertyID(int index);

  // prChangeControlValue - Изменение значения контрола
  virtual bool OnChangeControlValue(long ctrlID, const VARIANT & newVal);

  // prButtonUpdate        - Установка состояния кнопки спецпанели.
  virtual BOOL ButtonUpdate(long buttonID, long * check,
                                           VARIANT_BOOL * enable);
  // prButtonClick - Нажатие кнопки.
  virtual BOOL ButtonClick( long buttonID );
  // prControlCommand Нажатие кнопки контрола
  virtual BOOL ControlCommand(LPDISPATCH ctrl, long buttonID);

  //ksPlacementChanged     Изменение положения.
  virtual int  PlacementChanged(LPDISPATCH object);
  // ksFilterProc         - Фильтрация объектов
  virtual BOOL FilterProc      (LPDISPATCH object);
  // prFillContextPanel  -  Накачка контекстной панели 
  virtual BOOL FillContextPanel(LPDISPATCH ContextPanel);
    // Получение типа контекстного меню
  virtual BOOL GetContextMenuType(long LX, long LY, long * ContextMenuType);

  // Выбор грани
  void ChoiceFaces();
  //Установка первой грани
  void SetFace1(ksAPI7::IModelObjectPtr  face);
  //Установка второй грани
  void SetFace2(ksAPI7::IModelObjectPtr  face);
  // Получение первой грани
  ksAPI7::IModelObjectPtr GetFace1();
  // Получение второй грани
  ksAPI7::IModelObjectPtr GetFace2();
  _bstr_t  GetVariableExpression();

  // Наполнение контролов элемента
  virtual void ShowControls();

};

