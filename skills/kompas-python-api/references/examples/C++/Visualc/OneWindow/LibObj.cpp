////////////////////////////////////////////////////////////////////////////////
//
// Базовый класс для элементов
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "LibObj.h"
#include "events\DocumentFrameEvent.h"
#include <Math.h>
#include <SArray.h>
#include <SSArray.h>
#include <algorithm>  

#include <GL\gl.h>

#pragma comment(lib, "opengl32.lib")
//#pragma comment(lib, "glu32.lib")
//#pragma comment(lib, "glaux.lib")


#define   LENGTH_EPSILON    1E-10 // погрешность длины


extern IApplicationPtr newKompasAPI; // Интерфейс Приложения Компас 
extern HINSTANCE g_hInstance;
PArray<LibObj> m_libObjects;
LibObj* LibObj::editObj = NULL;


#define SELECT    "SELECT" 
#define ROOT      "ROOT" 
#define FORCES    "FORCES" 
#define FOLDER    "FOLDER"
#define EXPAND    "EXPAND"
#define GRIDEDGES "GRIDEDGES"
#define STRAINS   "STRAINS"  
#define FORCES_TREE _T("FORCES TREE") 

#define ARROW_M3D  _T("\\Models\\Стрелка нагрузки.m3d") 
#define STRAIN_M3D _T("\\Models\\Нагружаемая деталь_def.m3d")

#define LIBVERSION 1l

//-----------------------------------------------------------------------------
//
// ---
LibObj* FindOrCreateLibObj(IDocumentFramePtr& docFrame, bool create)
{
  LibObj* res = nullptr;
  if (docFrame)
  {
    LibObj* next = nullptr;
    for (int i = 0, count = m_libObjects.Count(); i < count; i++)
    {
      next = m_libObjects[i];
      if (next && next->IsMyFrame(docFrame))
      {
        res = next;
        break;
      }
    }
    if (!res && create)
    {
      res = new LibObj(docFrame);
      m_libObjects.Add(res);
    }
  }
  return res;
}


//------------------------------------------------------------------------------
// возвращает полное имя файла (by AVR)
// ---
bool GetFullName(LPCTSTR inName, LPTSTR outName, int outNameLen)
{
  bool     rez; // результат поиска файла name
  OFSTRUCT ofs;

  if (::GetModuleFileName(OneWindowDLL.hModule, outName, outNameLen))
  {
    TCHAR* c = ::_tcsrchr(outName, _T('\\'));
    if (c)
    {
      *(c + 1) = _T('\0');
      ::_tcscat_s(outName, 255, inName);
      rez = ::OpenFile(_bstr_t(outName), &ofs, OF_EXIST) != HFILE_ERROR;
      if (!rez)
      {
        *(c + 1) = _T('\0');
        ::_tcscat_s(outName, 255, _T("LOAD\\"));
        ::_tcscat_s(outName, 255, inName);
        rez = ::OpenFile(_bstr_t(outName), &ofs, OF_EXIST) != HFILE_ERROR;
      }
    }
  }

  if (!rez)
  {
    ::ksGetFullPathFromSystemPathT((LPTSTR)inName,         // относительный путь к файлу( без системного пути )
      outName,        // (результат) полный путь к файлу
      outNameLen,     // размер буфера
      sptSYSTEM_FILES // путь установленного типа см. ksSystemPath
    );

    rez = ::OpenFile(_bstr_t(outName), &ofs, OF_EXIST) != HFILE_ERROR;
  }

  return rez;
}

void Point3D::Transform(const Matrix3D& mtr)
{
  double xx = x * mtr.el[0][0] + y * mtr.el[1][0] + z * mtr.el[2][0] + mtr.el[3][0];
  double yy = x * mtr.el[0][1] + y * mtr.el[1][1] + z * mtr.el[2][1] + mtr.el[3][1];
  double zz = x * mtr.el[0][2] + y * mtr.el[1][2] + z * mtr.el[2][2] + mtr.el[3][2];

  x = x;
  y = y;
  z = z;
}


//-----------------------------------------------------------------------------
// Единичная матрица
// ---
void Matrix3D::Init()
{
  el[0][1] = el[0][2] = el[0][3] = 0.0;
  el[1][0] = el[1][2] = el[1][3] = 0.0;
  el[2][0] = el[2][1] = el[2][3] = 0.0;
  el[3][0] = el[3][1] = el[3][2] = 0.0;
  el[0][0] = 1.0;
  el[1][1] = 1.0;
  el[2][2] = 1.0;
  el[3][3] = 1.0;
}


//-----------------------------------------------------------------------------
// el указатель на массив double[16]
// ---
Matrix3D::Matrix3D(double* el16)
{
  el[0][0] = el16[0];
  el[0][1] = el16[1];
  el[0][2] = el16[2];
  el[0][3] = el16[3];
  el[1][0] = el16[4];
  el[1][1] = el16[5];
  el[1][2] = el16[6];
  el[1][3] = el16[7];
  el[2][0] = el16[8];
  el[2][1] = el16[9];
  el[2][2] = el16[10];
  el[2][3] = el16[11];
  el[3][0] = el16[12];
  el[3][1] = el16[13];
  el[3][2] = el16[14];
  el[3][3] = el16[15];
}

//-----------------------------------------------------------------------------
//
// ---
void Matrix3D::Init(Point3D& original,
  Vector3D& normal,
  Vector3D& axisX,
  Vector3D& axisY)
{
  GetOrigin() = original;
  GetAxisX() = axisX;  // Единичный вектор
  GetAxisY() = axisY;  // Единичный вектор
  GetAxisZ() = normal; // Единичный вектор
}


//-----------------------------------------------------------------------------
//
// ---
void Matrix3D::Init(ISurface& surf,         // Математическая поверхность
  bool       isSameSense,  // совпадает ли направление с нормалью поверхности или оно противоположное
  double     u,            // параметр u 
  double     v)           // параметр v;   
{
  Init();
  Point3D& original = GetOrigin();
  surf.GetPoint(u, v, &original.x, &original.y, &original.z);
  Vector3D& ax = GetAxisX();
  surf.GetTangentVectorU(u, v, &ax.x, &ax.y, &ax.z); // Косательный вектор по U

  Vector3D& ay = GetAxisY();
  surf.GetTangentVectorV(u, v, &ay.x, &ay.y, &ay.z); // Косательный вектор по V

  Vector3D& az = GetAxisZ();
  surf.GetNormal(u, v, &az.x, &az.y, &az.z); // Нормаль в точке uv
  if (!isSameSense) // Нужно развернуть ось z и ось y вокруг оси x
  {
    // Развернем ось Z
    az.x = -az.x;
    az.y = -az.y;
    az.z = -az.z;
    // Развернем ось Y
    ay.x = -ay.x;
    ay.y = -ay.y;
    ay.z = -ay.z;
  }
}


//------------------------------------------------------------------------------
// проверка на равенство матриц
// ---
bool Matrix3D::operator == (const Matrix3D& m) const {
  bool bRes = true;
  for (int i = 0; (i < 4) && bRes; i++) {
    bRes = ((::fabs(el[i][0] - m.el[i][0]) <= LENGTH_EPSILON) &&
      (::fabs(el[i][1] - m.el[i][1]) <= LENGTH_EPSILON) &&
      (::fabs(el[i][2] - m.el[i][2]) <= LENGTH_EPSILON) &&
      (::fabs(el[i][3] - m.el[i][3]) <= LENGTH_EPSILON));
  }
  return bRes;
}


//------------------------------------------------------------------------------
// умножение на матрицу this = this * b;
// ---
Matrix3D staticMatrix; // для ускорения вычислений
void Matrix3D::Multiply(const Matrix3D& b) {
  staticMatrix.Init(b, *this);
  ::memcpy(el, staticMatrix.el, sizeof(el));
}

//------------------------------------------------------------------------------
// получить оператор this = (B * A), Init( A, B ) != A * B !!!
// ---
void Matrix3D::Init(const Matrix3D& A, const Matrix3D& B) {

  el[0][0] = (A.el[0][0] * B.el[0][0] + A.el[1][0] * B.el[0][1] + A.el[2][0] * B.el[0][2]);
  el[0][1] = (A.el[0][1] * B.el[0][0] + A.el[1][1] * B.el[0][1] + A.el[2][1] * B.el[0][2]);
  el[0][2] = (A.el[0][2] * B.el[0][0] + A.el[1][2] * B.el[0][1] + A.el[2][2] * B.el[0][2]);

  el[1][0] = (A.el[0][0] * B.el[1][0] + A.el[1][0] * B.el[1][1] + A.el[2][0] * B.el[1][2]);
  el[1][1] = (A.el[0][1] * B.el[1][0] + A.el[1][1] * B.el[1][1] + A.el[2][1] * B.el[1][2]);
  el[1][2] = (A.el[0][2] * B.el[1][0] + A.el[1][2] * B.el[1][1] + A.el[2][2] * B.el[1][2]);

  el[2][0] = (A.el[0][0] * B.el[2][0] + A.el[1][0] * B.el[2][1] + A.el[2][0] * B.el[2][2]);
  el[2][1] = (A.el[0][1] * B.el[2][0] + A.el[1][1] * B.el[2][1] + A.el[2][1] * B.el[2][2]);
  el[2][2] = (A.el[0][2] * B.el[2][0] + A.el[1][2] * B.el[2][1] + A.el[2][2] * B.el[2][2]);

  el[3][0] = (A.el[0][0] * B.el[3][0] + A.el[1][0] * B.el[3][1] + A.el[2][0] * B.el[3][2]);
  el[3][1] = (A.el[0][1] * B.el[3][0] + A.el[1][1] * B.el[3][1] + A.el[2][1] * B.el[3][2]);
  el[3][2] = (A.el[0][2] * B.el[3][0] + A.el[1][2] * B.el[3][1] + A.el[2][2] * B.el[3][2]);


  el[3][0] += (A.el[3][0] * B.el[3][3]);
  el[3][1] += (A.el[3][1] * B.el[3][3]);
  el[3][2] += (A.el[3][2] * B.el[3][3]);

  el[0][3] = 0.0;
  el[1][3] = 0.0;
  el[2][3] = 0.0;

  el[3][3] = (A.el[3][3] * B.el[3][3]);

}


//------------------------------------------------------------------------------
// обращение квадратной матрицы
// ---
void Matrix3D::Div(Matrix3D& m) const {

  m.Init(); // делаем единичной матрицу

  double a11 = (el[1][1] * (el[2][3] * el[3][2] - el[2][2] * el[3][3]) + el[1][2] * (el[2][1] * el[3][3] - el[2][3] * el[3][1]) + el[1][3] * (el[2][2] * el[3][1] - el[2][1] * el[3][2]));
  double a12 = (el[1][0] * (el[2][2] * el[3][3] - el[2][3] * el[3][2]) + el[1][2] * (el[2][3] * el[3][0] - el[2][0] * el[3][3]) + el[1][3] * (el[2][0] * el[3][2] - el[2][2] * el[3][0]));
  double a13 = (el[1][0] * (el[2][3] * el[3][1] - el[2][1] * el[3][3]) + el[1][1] * (el[2][0] * el[3][3] - el[2][3] * el[3][0]) + el[1][3] * (el[2][1] * el[3][0] - el[2][0] * el[3][1]));
  double a14 = (el[1][0] * (el[2][1] * el[3][2] - el[2][2] * el[3][1]) + el[1][1] * (el[2][2] * el[3][0] - el[2][0] * el[3][2]) + el[1][2] * (el[2][0] * el[3][1] - el[2][1] * el[3][0]));

  double det = (el[0][0] * a11 + el[0][1] * a12 + el[0][2] * a13 + el[0][3] * a14);

  if (::fabs(det) > LENGTH_EPSILON) {

    det = (1.0 / det);

    m.el[0][0] = (a11 * det);
    m.el[1][0] = (a12 * det);
    m.el[2][0] = (a13 * det);
    m.el[3][0] = (a14 * det);

    m.el[0][1] = ((el[0][1] * (el[2][2] * el[3][3] - el[2][3] * el[3][2]) + el[0][2] * (el[2][3] * el[3][1] - el[2][1] * el[3][3]) + el[0][3] * (el[2][1] * el[3][2] - el[2][2] * el[3][1])) * det);
    m.el[1][1] = ((el[0][0] * (el[2][3] * el[3][2] - el[2][2] * el[3][3]) + el[0][2] * (el[2][0] * el[3][3] - el[2][3] * el[3][0]) + el[0][3] * (el[2][2] * el[3][0] - el[2][0] * el[3][2])) * det);
    m.el[2][1] = ((el[0][0] * (el[2][1] * el[3][3] - el[2][3] * el[3][1]) + el[0][1] * (el[2][3] * el[3][0] - el[2][0] * el[3][3]) + el[0][3] * (el[2][0] * el[3][1] - el[2][1] * el[3][0])) * det);
    m.el[3][1] = ((el[0][0] * (el[2][2] * el[3][1] - el[2][1] * el[3][2]) + el[0][1] * (el[2][0] * el[3][2] - el[2][2] * el[3][0]) + el[0][2] * (el[2][1] * el[3][0] - el[2][0] * el[3][1])) * det);

    m.el[0][2] = ((el[0][1] * (el[1][3] * el[3][2] - el[1][2] * el[3][3]) + el[0][2] * (el[1][1] * el[3][3] - el[1][3] * el[3][1]) + el[0][3] * (el[1][2] * el[3][1] - el[1][1] * el[3][2])) * det);
    m.el[1][2] = ((el[0][0] * (el[1][2] * el[3][3] - el[1][3] * el[3][2]) + el[0][2] * (el[1][3] * el[3][0] - el[1][0] * el[3][3]) + el[0][3] * (el[1][0] * el[3][2] - el[1][2] * el[3][0])) * det);
    m.el[2][2] = ((el[0][0] * (el[1][3] * el[3][1] - el[1][1] * el[3][3]) + el[0][1] * (el[1][0] * el[3][3] - el[1][3] * el[3][0]) + el[0][3] * (el[1][1] * el[3][0] - el[1][0] * el[3][1])) * det);
    m.el[3][2] = ((el[0][0] * (el[1][1] * el[3][2] - el[1][2] * el[3][1]) + el[0][1] * (el[1][2] * el[3][0] - el[1][0] * el[3][2]) + el[0][2] * (el[1][0] * el[3][1] - el[1][1] * el[3][0])) * det);

    m.el[0][3] = ((el[0][1] * (el[1][2] * el[2][3] - el[1][3] * el[2][2]) + el[0][2] * (el[1][3] * el[2][1] - el[1][1] * el[2][3]) + el[0][3] * (el[1][1] * el[2][2] - el[1][2] * el[2][1])) * det);
    m.el[1][3] = ((el[0][0] * (el[1][3] * el[2][2] - el[1][2] * el[2][3]) + el[0][2] * (el[1][0] * el[2][3] - el[1][3] * el[2][0]) + el[0][3] * (el[1][2] * el[2][0] - el[1][0] * el[2][2])) * det);
    m.el[2][3] = ((el[0][0] * (el[1][1] * el[2][3] - el[1][3] * el[2][1]) + el[0][1] * (el[1][3] * el[2][0] - el[1][0] * el[2][3]) + el[0][3] * (el[1][0] * el[2][1] - el[1][1] * el[2][0])) * det);
    m.el[3][3] = ((el[0][0] * (el[1][2] * el[2][1] - el[1][1] * el[2][2]) + el[0][1] * (el[1][0] * el[2][2] - el[1][2] * el[2][0]) + el[0][2] * (el[1][1] * el[2][0] - el[1][0] * el[2][1])) * det);
  }
}


//-------------------------------------------------------------------------------
// Создать массив SafeArray типа double
// ---
VARIANT CreateSafeArray(SArray<Point3D>& points)
{
  VARIANT varRow;
  VariantInit(&varRow);

  int varsCount = points.Count() * 3;

  SAFEARRAYBOUND sabNewArray;
  sabNewArray.cElements = varsCount;
  sabNewArray.lLbound = 0;

  SAFEARRAY* pSafe = ::SafeArrayCreate(VT_R8, 1, &sabNewArray);

  if (pSafe)
  {
    for (long i = 0, j = 0, count = points.Count(); i < count; i++, j++)
    {
      Point3D& point = points[i];
      ::SafeArrayPutElement(pSafe, &j, &point.x);
      j++;
      ::SafeArrayPutElement(pSafe, (long*)&j, (void*)&point.y);
      j++;
      ::SafeArrayPutElement(pSafe, (long*)&j, (void*)&point.z);
    }

    V_VT(&varRow) = VT_ARRAY | VT_R8;
    V_ARRAY(&varRow) = pSafe;
  }
  return varRow;
}


//-------------------------------------------------------------------------------
// Создать массив SafeArray типа double
// ---
VARIANT CreateSafeArray(SArray<Matrix3D>& matrix)
{
  VARIANT varRow;
  VariantInit(&varRow);

  int varsCount = matrix.Count() * 16;

  SAFEARRAYBOUND sabNewArray;
  sabNewArray.cElements = varsCount;
  sabNewArray.lLbound = 0;

  SAFEARRAY* pSafe = ::SafeArrayCreate(VT_R8, 1, &sabNewArray);

  if (pSafe)
  {
    for (long i = 0, j = 0, count = matrix.Count(); i < count; i++)
    {
      Matrix3D& m = matrix[i];
      for (int ei = 0; ei < 4; ei++)
      {
        for (int ej = 0; ej < 4; ej++)
        {
          ::SafeArrayPutElement(pSafe, &j, &m.el[ei][ej]);
          j++;
        }
      }
    }

    V_VT(&varRow) = VT_ARRAY | VT_R8;
    V_ARRAY(&varRow) = pSafe;
  }
  return varRow;
}


//-------------------------------------------------------------------------------
// Создать массив SafeArray типа double
// ---
VARIANT CreateSafeArray(SArray<long>& arr)
{
  VARIANT varRow;

  VariantInit(&varRow);

  int varsCount = arr.Count();
  SAFEARRAYBOUND sabNewArray;
  sabNewArray.cElements = varsCount;
  sabNewArray.lLbound = 0;

  SAFEARRAY* pSafe = ::SafeArrayCreate(VT_I4, 1, &sabNewArray);

  if (pSafe)
  {
    for (long i = 0; i < varsCount; i++)
    {
      ::SafeArrayPutElement(pSafe, (long*)&i, (void*)&arr[i]);
    }

    V_VT(&varRow) = VT_ARRAY | VT_I4;
    V_ARRAY(&varRow) = pSafe;
  }
  return varRow;
}


//-------------------------------------------------------------------------------
// Создать массив SafeArray типа double
// ---
BOOL SafeArrayToSArray(const VARIANT& arr, SArray<Point3D>& points)
{
  BOOL res = FALSE;
  if (arr.vt == (VT_ARRAY | VT_R8) && arr.parray) {
    //массив должен быть одномерный и количество точек должно быть кратно трем
    int count = arr.parray->rgsabound[0].cElements;
    if (arr.parray->cDims == 1 && count && !(count % 3))
    {
      HRESULT hr;
      double HUGEP* pvar;
      hr = ::SafeArrayAccessData(arr.parray, (void HUGEP * FAR*) & pvar);
      if (!FAILED(hr) && pvar)
      {
        count = count / 3;

        // Добавить точку в определение новой кривой
        for (int i = 0; i < count; i++) {
          Point3D point(pvar[i * 3], pvar[i * 3 + 1], pvar[i * 3 + 2]);
          points.Add(point);
        }

        hr = ::SafeArrayUnaccessData(arr.parray);
        if (!FAILED(hr))
          res = TRUE;
      }
    }
  }
  return res;
}

//-------------------------------------------------------------------------------
// Создать массив SafeArray типа double
// ---
BOOL SafeArrayToSArray(const VARIANT& arr, SArray<long>& sArr)
{
  BOOL res = FALSE;
  if (arr.vt == (VT_ARRAY | VT_I4) && arr.parray) {
    //массив должен быть одномерный и количество точек должно быть кратно трем
    int count = arr.parray->rgsabound[0].cElements;
    if (arr.parray->cDims == 1 && count)
    {
      HRESULT hr;
      long HUGEP* pvar;
      hr = ::SafeArrayAccessData(arr.parray, (void HUGEP * FAR*) & pvar);
      if (!FAILED(hr) && pvar)
      {

        // Добавить точку в определение новой кривой
        for (int i = 0; i < count; i++) {
          sArr.Add(pvar[i]);
        }

        hr = ::SafeArrayUnaccessData(arr.parray);
        if (!FAILED(hr))
          res = TRUE;
      }
    }
  }
  else
    if (arr.vt == VT_I4)
      sArr.Add(arr.lVal);
  return res;
}

//-------------------------------------------------------------------------------
// Создать массив SafeArray типа double
// ---
BOOL SafeArrayToSArray(const VARIANT& arr, SArray<Matrix3D>& sArr)
{
  BOOL res = FALSE;
  if (arr.vt == (VT_ARRAY | VT_R8) && arr.parray) {
    //массив должен быть одномерный и количество точек должно быть кратно трем
    int count = arr.parray->rgsabound[0].cElements;
    if (arr.parray->cDims == 1 && count && !(count % 16))
    {
      HRESULT hr;
      double HUGEP* pvar;
      hr = ::SafeArrayAccessData(arr.parray, (void HUGEP * FAR*) & pvar);
      if (!FAILED(hr) && pvar)
      {
        count = count / 16;

        // Добавить точку в определение новой кривой
        for (int i = 0; i < count; i++)
        {

          Matrix3D m(&pvar[i * 16]);
          sArr.Add(m);
        }

        hr = ::SafeArrayUnaccessData(arr.parray);
        if (!FAILED(hr))
          res = TRUE;
      }
    }
  }
  return res;
}

//-----------------------------------------------------------------------------
//
// ---
template < class T >
VARIANT CreateDispSafeArray(PArray<T>& objects)
{
  VARIANT res;
  ::VariantInit(&res); // На всякй случай

  int count = objects.Count();
  if (count)
  {

    SAFEARRAYBOUND sabNewArray;
    sabNewArray.cElements = count;
    sabNewArray.lLbound = 0;

    // Выделяем память под массив
    SAFEARRAY __RPC_FAR* psa = SafeArrayCreate(VT_DISPATCH, 1, &sabNewArray);
    res.vt = VT_ARRAY | VT_DISPATCH;
    res.parray = psa;

    for (long i = 0; i < count; i++)        // Пройдём по всем объектам
    {
      // Переведём в новое API
      IDispatchPtr obj7(IUnknownPtr(::ksTransferInterface(*objects[i], ksAPI7Dual, 0), false/*AddRef*/));
      // Положим его в массив
      ::SafeArrayPutElement(psa, &i, (void*)(LPDISPATCH)obj7);
    }
  }
  return res;
}

//-----------------------------------------------------------------------------
//
// ---
template < class T >
void FillObjectsDefinitions(_variant_t& varArr, PArray<T>& objects)
{
  if (varArr.vt == (VT_ARRAY | VT_DISPATCH) && varArr.parray)
  {
    LPDISPATCH obj = nullptr;
    int count = varArr.parray->rgsabound[0].cElements;
    for (long i = 0; i < count; i++)        // Пройдём по всем объектам
    {
      SafeArrayGetElement(varArr.parray, &i, &obj);
      // Переведём в новое API
      if (obj)
      {
        IEntityPtr newObj(IUnknownPtr(ksTransferInterface(obj, ksAPI3DCom, o3d_entity), false/*AddRef*/));
        if (newObj)
        {
          IUnknownPtr def(newObj->GetDefinition(), false/*AddRef*/);
          T tDef(def);
          if (tDef)
            objects.Add(new T(tDef));
        }
        obj->Release();
        obj = nullptr;
      }
    }
  }
  else if (varArr.vt == VT_DISPATCH)
  {
    IEntityPtr newObj(IUnknownPtr(ksTransferInterface(varArr.pdispVal, ksAPI3DCom, o3d_entity), false/*AddRef*/));
    if (newObj)
    {
      IUnknownPtr def(newObj->GetDefinition(), false/*AddRef*/);
      T tDef(def);
      if (tDef)
        objects.Add(new T(tDef));
    }
  }
}


//-----------------------------------------------------------------------------
//
// ---
struct GrridEdge
{
  long m_i1;
  long m_i2;
  GrridEdge(long i1, long i2)
    : m_i1(i1 > i2 ? i2 : i1)
    , m_i2(i1 > i2 ? i1 : i2)
  {
  }

  bool operator==(const GrridEdge& other) const
  {
    return (m_i1 == other.m_i1 && m_i2 == other.m_i2);
  }

  bool operator <(const GrridEdge& other) const  // проверка на неравенство
  {
    return (m_i1 < other.m_i1) || ((m_i1 == other.m_i1) && (m_i2 < other.m_i2));
  }


};


#pragma warning( disable : 4786 ) 
//-----------------------------------------------------------------------------
// Конструктор для получения триангуляции грани и полигона для кривой
// ---
ExternalTeselationParam::ExternalTeselationParam(IEntityPtr& obj, IPartPtr& topPart)
  : color(0) // Цвет 
  , ambient(1) // общий свет
  , diffuse(1) // диффузия
  , specularity(1) // зеркальность
  , shininess(1) // блеск 
  , transparency(1) // прозрачность
  , emission(1) // излучение
  , edge(false) // Ребро или грань
{
  if (obj)
  {
    IUnknownPtr def(obj->GetDefinition(), false/*addRef*/);
    if (def)
    {
      if (obj->GetType() == o3d_face)
      {
        obj->GetAdvancedColor(&color, &ambient, &diffuse, &specularity, &shininess, &transparency, &emission);
        if (transparency > 0.001) // Если объект не абсолютно прозрачен 
          InitByFace(IFaceDefinitionPtr(def));
      }
      else if (obj->GetType() == o3d_edge)
      {
        IEdgeDefinitionPtr edgeDef(def);
        if (edgeDef)
        {
          IFaceDefinitionPtr face(edgeDef->GetAdjacentFace(false), false/*AddRef*/);
          if (face)
          {
            InitByEdge(edgeDef);
            edge = true;
            color = RGB(0, 0, 0);
          }
        }
      }
      IPartPtr parentPart;
      if (topPart)
      {
        parentPart.Attach(obj->GetParent(), false/*addRef*/);
        if (topPart == parentPart)
          parentPart = nullptr;
      }

      if (parentPart)
      {
        if (points.vt == (VT_ARRAY | VT_R8))
          topPart->TransformPoints(&points, parentPart);

        if (normals.vt == (VT_ARRAY | VT_R8))
        {
          double x0 = 0.0, y0 = 0.0, z0 = 0.0;
          topPart->TransformPoint(&x0, &y0, &z0, parentPart);
          if (fabs(x0) > LENGTH_EPSILON ||
            fabs(y0) > LENGTH_EPSILON ||
            fabs(z0) > LENGTH_EPSILON)
          {
            topPart->TransformPoints(&normals, parentPart);
            SArray<Point3D> normalsArr;
            SafeArrayToSArray(normals, normalsArr);
            Point3D p0(x0, y0, z0);
            for (int i = 0, count = normalsArr.Count(); i < count; i++)
            {
              normalsArr[i] -= p0;
            }
            normals.Attach(CreateSafeArray(normalsArr));
          }
        }
      }
    }
  }
}
#pragma warning( once : 4786 ) 

//-----------------------------------------------------------------------------
// Упаковать все ребра в один внешний объект
// ---
ExternalTeselationParam::ExternalTeselationParam(PArray<ExternalTeselationParam>& params)
  : color(RGB(0, 0, 0)) // Цвет 
  , ambient(1) // общий свет
  , diffuse(1) // диффузия
  , specularity(1) // зеркальность
  , shininess(1) // блеск 
  , transparency(1) // прозрачность
  , emission(1) // излучение
  , edge(true) // Ребро или грань
{
  PacEdges(params);
}


//-----------------------------------------------------------------------------
// Получение параметров триангуляции
// ---
void ExternalTeselationParam::InitByFace(IFaceDefinitionPtr& faceDef)
{
  if (faceDef)
  {
    BOOL plane = faceDef->IsPlanar();
    ITessellationPtr tess(faceDef->GetTessellation(), false/*addRef*/);
    if (tess)
    {
      if (plane)
      {
        float x, y, z;
        tess->GetNormal(0, &x, &y, &z);   // Для плоской грани нормаль одна на все точки
        SArray<Point3D> norm;
        norm.Add(Point3D(x, y, z));
        normals.Attach(CreateSafeArray(norm));
      }
      else
        tess->GetFacetNormals(&normals);

      tess->GetFacetPoints(&points, &indexes);
    }
  }
}


//-----------------------------------------------------------------------------
//
// ---
void ExternalTeselationParam::InitByEdge(IEdgeDefinitionPtr& edgeDef)
{
  if (edgeDef)
  {
    ICurve3DPtr curve(edgeDef->GetCurve3D(), false/*addRef*/);
    if (curve)
    {
      BOOL line = curve->IsLineSeg();
      if (line) // Если это отрезок то будем рисовать его по двум точкам
      {
        SArray<Point3D> p;
        double x, y, z;
        curve->GetPoint(curve->GetParamMin(), &x, &y, &z);
        p.Add(Point3D(x, y, z));
        curve->GetPoint(curve->GetParamMax(), &x, &y, &z);
        p.Add(Point3D(x, y, z));
        points.Attach(CreateSafeArray(p));
      }
      else
        curve->CalculatePolygon(0/*step*/, &points); // Расчитываем полигон для кривой

      if (points.vt == (VT_ARRAY | VT_R8) && points.parray)
      {
        SArray<long> ind;
        long count = points.parray->rgsabound[0].cElements / 3;
        ind.Add(count);
        for (int i = 0; i < count; i++)
        {
          ind.Add(i);
        }

        indexes.Attach(CreateSafeArray(ind));
      }
    }
  }
}


//-----------------------------------------------------------------------------
// Упаковать параметры ребер в один элемент
// ---
void ExternalTeselationParam::PacEdges(PArray<ExternalTeselationParam>& params)
{
  SArray<Point3D> p;
  SArray<long>    edges;
  for (int i = 0, count = params.Count(); i < count; i++)
  {
    if (params[i]->edge)
    {
      long oldCount = p.Count();
      SafeArrayToSArray(params[i]->points, p);
      long newCount = p.Count();
      edges.Add(newCount - oldCount);
      for (int j = oldCount; j < newCount; j++)
        edges.Add(j); // новый индекс 
    }
  }
  points.Attach(CreateSafeArray(p));
  indexes.Attach(CreateSafeArray(edges));

}


//----------------------------------------------------------------
// Получение массива партов из SafeArray-я
// ---
void FillParts(_variant_t& parts, PArray<IPartPtr>& partsArr)
{
  int count = parts.parray->rgsabound[0].cElements;
  if (parts.parray->cDims == 1 && count)
  {
    LPDISPATCH obj = nullptr;
    for (long i = 0; i < count; i++)
    {
      SafeArrayGetElement(parts.parray, &i, &obj); // Делает AddRef
      if (obj)
      {
        IPartPtr newPart(IUnknownPtr(ksTransferInterface(obj, ksAPI3DCom, o3d_part), false/*AddRef*/));
        if (newPart)
          partsArr.Add(new IPartPtr(newPart));

        obj->Release(); //  
      }
    }
  }
}


//-----------------------------------------------------------------------------------------------------------
// Получение триангуляции из компонента
// ---
void LoadTessellations(PArray<ExternalTeselationParam>& params, IPartPtr& topPart, IPartPtr& nextPart)
{
  if (nextPart)
  {
    IEntityPtr pointCS(nextPart->GetDefaultEntity(o3d_pointCS), false);
    if (pointCS)
    {
      pointCS->SetHidden(TRUE);
      pointCS->Update();
    }
    IEntityCollectionPtr coll(nextPart->EntityCollection(o3d_face), false/*AddRef*/);
    if (coll)
    {
      for (int i = 0, count = coll->GetCount(); i < count; i++)
      {
        IEntityPtr entity(coll->GetByIndex(i), false/*AddRef*/);
        if (entity)
        {
          ExternalTeselationParam* param = new ExternalTeselationParam(entity, topPart);
          if (param->IsValid())
            params.Add(param);
          else
            delete param;
        }
      }
    }

    coll.Attach(nextPart->EntityCollection(o3d_edge), false/*AddRef*/);
    if (coll)
    {
      for (int i = 0, count = coll->GetCount(); i < count; i++)
      {
        IEntityPtr entity(coll->GetByIndex(i), false/*AddRef*/);
        if (entity)
        {
          ExternalTeselationParam* param = new ExternalTeselationParam(entity, topPart);
          if (param->IsValid())
            params.Add(param);
          else
            delete param;
        }
      }
    }

    if (!nextPart->IsDetail())
    {
      IPart7Ptr part7(IUnknownPtr(ksTransferInterface(nextPart, ksAPI7Dual, 0), false));
      if (part7)
      {
        PArray<IPartPtr> partsArr;
        {
          _variant_t parts(part7->PartsEx[(long)ksAllParts]); // Получаем все вставки в том числе и из массивов и макро
          FillParts(parts, partsArr);
        }
        for (int i = 0, count = partsArr.Count(); i < count; i++)
        {
          LoadTessellations(params, topPart, *partsArr[i]);
        }
      }
    }
  }
}


//------------------------------------------------------------------------------------
// Загрузка триангуляции из файла
// ---
bool LoadTessellations(PArray<ExternalTeselationParam>& params, _bstr_t& fileName)
{
  // Для примера загружаем триангуляцию с другой модели
  if (fileName.length() > 0)
  {
    IDocument3DPtr doc3D(ksGet3dDocument(), false/*AddRef*/);
    if ((bool)doc3D && doc3D->Open(fileName, 1))
    {
      {  // Освободим интерфейсы перед закрытием документа
        IPartPtr topPart(doc3D->GetPart(pTop_Part), false/*AddRef*/);
        if (topPart)
          LoadTessellations(params, topPart, topPart);
      }
      doc3D->Close();
      ResultNULL(); // Сбросить ошибку закрытия файла без сохранения
    }
  }
  return params.Count() > 0;
}



////////////////////////////////////////////////////////////////////////////////
//
// 
//
////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------------
// Конструктор
//---
LibObj::LibObj(IDocumentFramePtr& frame)
  : PropertyManagerObject()
  , m_command(0)
  , m_documentFrameEvent(nullptr)
  , m_arrowsIndex(1) // Счетчик для стрелок
  , m_newArrow(nullptr)
  , m_treeViewEvent(nullptr)
  , m_TreeVisible(true)
  , m_LoadTree(false)
  , m_currentCommand(-1)

{
  m_treeMenu.LoadMenu(IDM_TREE_MENU);
  m_treeMenu.EnableMenuItem(1, MF_BYPOSITION | MF_ENABLED);
  if (frame)
  {
    m_documentFrameEvent = NewDocumentFrameEvent(frame->GetParent(), frame, *this);
    LoadTree();
  }
}


//-----------------------------------------------------------------------------
//
// ---
LibObj::~LibObj()
{
  CloseTree();
  OffAllTessellations();
  delete m_documentFrameEvent;
}


//-----------------------------------------------------------------------------
//
// ---
void LibObj::OffAllTessellations()
{
  for (int i = 0, count = m_arrows.size(); i < count; i++)
    OnOffTesselations(m_arrows[i]->m_iids, false, m_arrows[i]->m_visible, true);
}


//-------------------------------------------------------------------------------
// Отработка изменений значения контрола
// ---
bool LibObj::OnChangeControlValue( /*IPropertyControl* cntrl,*/ long ctrlID, const VARIANT& newVal)
{
  return true;
}

//---------------------------------------------------------------------------------------------------- 
// Выполнить команду библиотеки
// ---
void ExecuteKompasLibraryCommand(long commandId)
{
  if (newKompasAPI)
  {
    auto item = newKompasAPI->LibraryManager->ProceduresLibraries->Item[LoadStr(IDR_LIBID)];
    if (item)
      item->Execute(commandId, nullptr, true);
  }
}


//---------------------------------------------------------------------------------------------------- 
// Обработка нажатия кнопок
// ---
bool LibObj::OnButtonClick(long buttonID)
{
  bool res = true;

  switch (buttonID)
  {
  case pbEnter:
  {
    if (m_newArrow && m_command)
    {
      m_newArrow->m_index = m_arrowsIndex;
      AddNode(MakeNodeName(LoadStr(IDP_FORCE), m_arrowsIndex), m_arrowsIndex);

      m_arrowsIndex++;

      m_newArrow = nullptr;
    }

    res = false; // Процесс не завершаем

    break;
  }

  case pbEsc:
  {
    if (editObj)
    {
      if (m_newArrow)
      {
        OnOffTesselations(m_newArrow->m_iids, false, true, true); // Удалить отрисовку элементов, которых нет в дереве
        std::remove(m_arrows.begin(), m_arrows.end(), m_newArrow);
        m_newArrow = nullptr;
      }

      IDocumentFramePtr frame(GetFrame());
      if (frame)
      {
        IKompasDocument3DPtr komDoc3D(frame->GetParent()->GetParent());
        IDocument3DPtr doc3D(IUnknownPtr(ksTransferInterface(komDoc3D, ksAPI3DCom, o3d_document), false));
        if (doc3D)
          doc3D->StopLibRequest();
      }
    }
    else
    {
      SaveTree();
      CloseTree();
      OffAllTessellations();
      delete m_documentFrameEvent;
      m_documentFrameEvent = nullptr;
    }

    break;
  }

  case IDM_BUTTON1_ID:
  {
    CreateForce();

    break;
  }

  case IDM_BUTTON2_ID:
  {
    ExecuteKompasLibraryCommand(4);
    break;
  }

  case IDM_BUTTON3_ID:
  {
    ExecuteKompasLibraryCommand(5);
    break;
  }
  }

  return res;
}


//-----------------------------------------------------------------------------
// prControlCommand Нажатие кнопки контрола
// ---
bool LibObj::OnControlCommand(long ctrlID, long buttonID)
{
  OnMenuCommand(buttonID);
  return true;
}


//-----------------------------------------------------------------------------
// prButtonUpdate        - Установка состояния кнопки спецпанели.
// ---
bool LibObj::OnButtonUpdate(long buttonID, long* check, VARIANT_BOOL* _enable)
{
  switch (buttonID)
  {
  case IDM_BUTTON1_ID:
    *_enable = !m_newArrow;
    break;
  }


  return true;
}


//-----------------------------------------------------------------------------
//
// ---
bool LibObj::IsMyFrame(IDocumentFramePtr& frame)
{
  return frame == GetFrame();
}

//----------------------------------------------------------------------------------------------------------------
// Получить окно
// ---
IDocumentFramePtr LibObj::GetFrame()
{
  return IDocumentFramePtr(m_documentFrameEvent ? m_documentFrameEvent->GetContainer(FALSE/*AddRef*/) : NULL);
}


//-----------------------------------------------------------------------------
// Создание диформационной нагрузки 
// ---
void LibObj::CreateForce()
{
  m_command = 1;
  if (!m_propMng)
    CreateTree();

  SelectFacesForForce();
  SaveTree();
}

_bstr_t GetLibraryIconFont()
{
  static _bstr_t iconfont;
  if (iconfont.length() == 0 && newKompasAPI)
  {
    IProceduresLibraryPtr lib(newKompasAPI->LibraryManager->ProceduresLibraries->Item[(LPCTSTR)LoadStr(IDR_LIBID)]);
    if (lib)
      iconfont = lib->IconsFont;
  }
  return iconfont;
}


//----------------------------------------------------------------------------------------------------------------------------
// Создание дерева нагрузок в окне документа
// ---
void LibObj::CreateTree()
{
  CRect g_Rect(20, 20, 270, 320);
  m_propMng = newKompasAPI->CreatePropertyManager(FALSE);
  if (m_propMng)
  {
    m_propMng->Layout = pmAlignRight;
    m_propMng->Caption = _T("Панель дерева");
    m_propMng->SetGabaritRect(g_Rect.left, g_Rect.top, g_Rect.right, g_Rect.bottom);
    m_propMng->SpecToolbar = pnEscHelp;

    _bstr_t font = GetLibraryIconFont();

    m_propMng->AddSpecToolbarButton(IDM_BUTTON1_ID, IDM_BUTTON1_ICON, LoadStr(IDS_BUTTON1_TIPS), font);
    m_propMng->AddSpecToolbarButton(IDM_BUTTON2_ID, IDM_BUTTON2_ICON, LoadStr(IDS_BUTTON2_TIPS), L"");
    m_propMng->AddSpecToolbarButton(IDM_BUTTON3_ID, IDM_BUTTON3_ICON, LoadStr(IDS_BUTTON3_TIPS), font);

    new PropertyManagerEvent(m_propMng, *this); // Пdдписываемся на события процесса 
    m_tab = m_propMng->PropertyTabs->Add(_T("Закладка дерева"));
    // Получаем коллекцию контролов
    IPropertyControlsPtr collection = m_tab->PropertyControls;
    if (!m_TreeCtrl && m_TreeVisible)
    {
      m_TreeCtrl = collection->Add(ksControlTree);
      if (m_TreeCtrl)
      {
        FillTree(m_TreeCtrl);  // Наполним дерево

        m_TreeCtrl->NameVisibility = ksNameAlwaysVisible;
        m_TreeCtrl->Name = L"Дерево";
        m_TreeCtrl->MinHeight = 100;
        m_TreeCtrl->Resizable = TRUE;
        m_TreeCtrl->Id = 1000;
        m_TreeCtrl->AutoSize = TRUE;
        m_TreeCtrl->MultiSelect = TRUE;
        m_treeViewEvent = new ATreeViewEvent(m_TreeCtrl, *this);
      }

      m_propMng->ShowTabs();
    }
  }
}


//-----------------------------------------------------------------------------
// Удаление дерева нагрузок
// ---
void LibObj::CloseTree()
{
  delete m_treeViewEvent;
  m_treeViewEvent = nullptr;

  if (m_propMng)
  {
    ABaseEvent::TerminateEvents(DIID_ksPropertyManagerNotify);

    m_propMng->HideTabs();
    m_TreeCtrl = nullptr;
    m_propMng = nullptr;

  }
}


//-----------------------------------------------------------------------------
// Показать\скрыть дерево
// ---
void LibObj::OnOfTree()
{
  m_TreeVisible = (bool)m_TreeCtrl && m_TreeVisible ? false : true;
  if (m_TreeVisible)
  {
    CreateTree();
    if (m_TreeCtrl)
      m_propMng->Visible = m_TreeVisible;
  }
  else
  {
    CloseTree();
  }
}

//-----------------------------------------------------------------------------
// Накачка дерева
// ---
void LibObj::FillTree(IPropertyTreePtr& tree)
{
  if (tree)
  {
    auto rootNode = tree->GetRootNode();
    if (rootNode)
      rootNode->Delete();

    _bstr_t iconFont = GetLibraryIconFont();

    rootNode = tree->CreateNode(_T("Дерево"));
    if (rootNode)
    {
      rootNode->ItemsHolder = TRUE;
      rootNode->SetNodeIcon(IDB_ROOT, iconFont);

      if (tree->AddNode(rootNode))
      {
        m_arrrowsNode = tree->CreateNode(_T("Нагрузки"));

        if (m_arrrowsNode)
        {
          m_arrrowsNode->ItemsHolder = TRUE;

          m_arrrowsNode->SetNodeIcon(IDB_ARROW, iconFont);

          if (rootNode->AddNode(m_arrrowsNode, nullptr))
            FillTreeNodes(m_arrows);
        }
      }
    }
  }
}

//----------------------------------------------------------------------------------------------
//
// ---
bool LibObj::CheckIfArrowNode(IPropertyTreeNodePtr node)
{
  if (node)
  {
    _bstr_t label = node->Text;
    return !(0 == wcscmp(label, L"Дерево") || wcscmp(label, L"Нагрузки") == 0);
  }

  return false;
}

//----------------------------------------------------------------------------------------------
//
// ---
BOOL LibObj::BeginPaintGL(IDocumentFramePtr& docFrame, ksGLObjectPtr& glObj, long drawMode)
{
  bool visible = false;
  if (visible)
  {
    // Стераем старое изображение
    ::glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    ::glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }

  return !visible;
}


// DocumentFrameEventCalback #########################################################
// frAddGabarit          - Определение габаритов документа
BOOL LibObj::AddGabarit(IDocumentFramePtr& docFrame, IGabaritObjectPtr& gabObj)
{
  bool arrowsVisible = IsArrowsVisible();

  if ((bool)gabObj && (arrowsVisible))
  {
    double x1;
    double y1;
    double z1;
    double x2;
    double y2;
    double z2;
    VARIANT_BOOL res = gabObj->GetCurrentGabarit(0, &x1, &y1, &z1, &x2, &y2, &z2);
    if (res) {
      double delta = 100;
      x1 -= delta;
      y1 -= delta;
      z1 -= delta;
      x2 += delta;
      y2 += delta;
      z2 += delta;
      res = gabObj->AddGabarit(x1, y1, z1, x2, y2, z2);
    }
  }
  return TRUE;
}


//-----------------------------------------------------------------------------
// frCloseFrame          - Закрытие окна
// ---
BOOL LibObj::CloseFrame(IDocumentFramePtr& docFrame)
{
  // Окно закрылось удалим себя
  m_libObjects.RemoveObj(this);
  return true;
}
// DocumentFrameEventCalback #########################################################


//------------------------------------------------------------------------------
// Функция фильтр
// ---
bool WINAPI LibObj::SELECTFILTERPROC(IEntity* entity)
{
  return entity && entity->IsIt(o3d_face); // Фильтруем только грани
}


//------------------------------------------------------------------------------
// Функция обратной связи
// ---
int WINAPI LibObj::SELECTCALLBACKPROC(IEntity* entity, IRequestInfo* info)
{
  BOOL res = FALSE;
  if (editObj && entity && entity->IsIt(o3d_face)) // Фильтруем только грани
  {
    IFaceDefinitionPtr faceDef(IUnknownPtr(entity->GetDefinition(), false/*AddRef*/));
    res = editObj->OnSelectFace(faceDef);
  }
  return res;
}


//-----------------------------------------------------------------------------
//
// ---
BOOL LibObj::OnSelectFace(IFaceDefinitionPtr& face)
{
  switch (m_command)
  {
  case 1: CreateForce(face); break; // Создание диформационной нагрузки
  }
  return TRUE;
}


#pragma warning( disable : 4786 )
//-----------------------------------------------------------------------------
// Получить суммарную матрицу пересчета координат из компонента в сборку 
// ---
bool GetSummMtr(IKompasDocument3DPtr& doc3D, Matrix3D& summMtr, IFaceDefinitionPtr& face)
{
  if ((bool)doc3D && (bool)face)
  {
    IPart7Ptr part7(doc3D->TopPart);

    IEntityPtr parent(face->GetEntity(), false/*AddRef*/);
    if ((bool)part7 && (bool)parent)
    {
      IPartPtr part(parent->GetParent(), false/*AddRef*/);
      IPartPtr topPart(IUnknownPtr(ksTransferInterface(part7, ksAPI3DCom, o3d_part), false/*AddRef*/));
      if (topPart != part)
      {
        _variant_t mtr;
        topPart->GetSummMatrix(&mtr, part); // получение суммарной матрицы для пересчета координат
        SArray<Matrix3D> arrMtr;
        SafeArrayToSArray(mtr, arrMtr);
        summMtr = arrMtr[0];
      }
    }
  }
  return !(summMtr == Matrix3D());
}
#pragma warning( once : 4786 ) 


//-----------------------------------------------------------------------------
// Загрузка триангуляции стрелки из файла
// ---
void LibObj::LoadArrowParams()
{
  if (arrowParams.Count() == 0) // Треангуляцию для стрелки не делали
  {
    TCHAR arrowFile[_MAX_PATH] = _T("");
    GetFullName(ARROW_M3D, arrowFile, _MAX_PATH);
    if (arrowFile[0])
    {
      // По первому требованию загружаем триангуляцию
      LoadTessellations(arrowParams, _bstr_t(arrowFile));
    }
    else
    {
      MessageT(_T("Не найден файл :" ARROW_M3D));
    }
  }
}

//-----------------------------------------------------------------------------
// Наполним узлы дерева
// ---
void LibObj::FillTreeNodes(std::vector<ArrowParam*>& nodeElements)
{
  for (int i = 0, count = nodeElements.size(); i < count; ++i)
  {
    ArrowParam* param = nodeElements[i];
    if (param)
    {
      long id = param->GetID();
      _bstr_t& name = param->m_name;
      AddNode(name.length() > 0 ? name : MakeNodeName(LoadStr(IDP_FORCE), id), id);
    }
  }
}


//-----------------------------------------------------------------------------
// Создание диформационной нагрузки
// ---
void LibObj::CreateForce(IFaceDefinitionPtr& face)
{
  LoadArrowParams();
  IDocumentFramePtr docFrame(GetFrame());
  if (docFrame)
  {
    if (!m_newArrow)
    {
      m_newArrow = new ArrowParam();
      m_arrows.push_back(m_newArrow);
    }

    m_newArrow->m_faces.Add(new IFaceDefinitionPtr(face));
    m_newArrow->m_visible = true;
    m_newArrow->Make(face, docFrame, arrowParams);

    docFrame->SetGabaritModifying();
    docFrame->RefreshWindow();
  }
}


//-----------------------------------------------------------------------------
// Расчет матриц для отрисовки стрелок
//-----------------------------------
// № пп  Параметр U, % Параметр V, %
// 1     0             0
// 2     0             50
// 3     0             100
// 4     50            0
// 5     50            50
// 6     50            100
// 7     100           0
// 8     100           50
// 9     100           100
// ---
void MakeMatrixes(ISurfacePtr& surf, bool isSameSense, SArray<Matrix3D>& matrix)
{
  if (surf)
  {
    double uMin = surf->GetParamUMin(),
      uMax = surf->GetParamUMax(),
      vMin = surf->GetParamVMin(),
      vMax = surf->GetParamVMax();
    double du = (uMax - uMin) * 0.5;
    double dv = (vMax - vMin) * 0.5;
    Matrix3D m;
    double u = uMin, v;
    for (int i = 0; i < 3; i++, u += du)
    {
      v = vMin;
      for (int j = 0; j < 3; j++, v += dv)
      {
        m.Init(surf, isSameSense, u, v);
        matrix.Add(m);
      }
    }
  }
}


//-----------------------------------------------------------------------------
// Запуск процесса указания граней для создания нагрузок
// ---
void LibObj::SelectFacesForForce()
{
  SelectFaces(IDP_FORCE, STR_SELECT_FACES);
}


//-----------------------------------------------------------------------------
// Запуск процесса указания граней для создания нагузок
// ---
void LibObj::SelectFaces(long procID, long promtID)
{
  m_propMng->Visible = FALSE;
  m_propMng->UpdateTabs();
  IDocumentFramePtr frame(GetFrame());
  if (frame)
  {
    IKompasDocument3DPtr komDoc3D(frame->GetParent()->GetParent());
    IDocument3DPtr doc3D(IUnknownPtr(ksTransferInterface(komDoc3D, ksAPI3DCom, o3d_document), false));
    if (doc3D)
    {
      IRequestInfoPtr info(doc3D->GetRequestInfo(nullptr), false/*AddRef*/);
      if (info)
      {
        // Укажите грани для создания нагрузок 
        info->SetPrompt(LoadStr(promtID));
        info->SetFilterCallBack(SELECTFILTERPROC);
        info->SetCallBack(SELECTCALLBACKPROC);
      }


      if (InitProcessParam(procID, pnEnterEscHelp, procID))
      {
        m_procParam->AutoReduce = false;

        info->SetProcessParam(m_procParam);
        editObj = this;

        doc3D->UserGetPlacementAndEntity(0);
        editObj = nullptr;
        EndProcess();
      }
      m_propMng->Visible = TRUE;
      m_propMng->UpdateTabs();
    }
  }
}


//-----------------------------------------------------------------------------
// Виртуальная функция наполнения контролов элемента
// ---
void  LibObj::ShowControls()
{
}


//-----------------------------------------------------------------------------
// Включение\выключение и удаление отрисовки внешних объектов для заданного окна 
// ---
void LibObj::OnOffTesselations(SArray<long>& iids, bool vis, bool oldVis, bool del)
{
  if (iids.Count())
  {
    IDocumentFramePtr frame(GetFrame());
    if (frame)
    {
      IKompasDocument3DPtr komDoc3D(frame->GetParent()->GetParent());
      IExternalTessellationManagerPtr mng(komDoc3D);
      if (mng)
      {
        _variant_t varIids(CreateSafeArray(iids), vis);
        if (vis != oldVis)
          mng->ObjectsVisible[varIids][frame] = vis;  // Скрыть\показать 
        if (del)
        {
          mng->DeleteObjects(varIids);              // Удалить
          iids.Flush();
        }
        frame->SetGabaritModifying();
        frame->RefreshWindow();
      }
    }
  }
}


//-----------------------------------------------------------------------------
// Добавление узла дерева
// ---
bool LibObj::AddNode(const _bstr_t& nodeName, int index)
{
  bool res = false;

  if (m_arrrowsNode && m_TreeCtrl)
  {
    auto node = m_TreeCtrl->CreateNode(nodeName);
    if (node)
    {
      res = m_arrrowsNode->AddNode(node, nullptr);
      node->SetNodeIcon(IDS_FORCE, GetLibraryIconFont());
      node->NodeData = index;
    }
  }

  return res;
}


//-----------------------------------------------------------------------------
// Составить имя для узла
// ---
LPCTSTR LibObj::MakeNodeName(LPCTSTR name, int index)
{
  static CString nodeName;
  if (index != 0)
    nodeName.Format(_T("%s:%i"), name, index);
  else
    nodeName = name;
  return nodeName;
}


//-----------------------------------------------------------------------------
//
// ---
bool LibObj::IsArrowsVisible()
{
  bool res = !!m_newArrow;
  for (int i = 0, count = m_arrows.size(); i < count && !res; i++)
    res = m_arrows[i]->m_visible;
  return res;
}

// �������������� VARIANT � SAFARRAY � ������ �������� ��������� ����
template <class Type>
void FillVector(const VARIANT& vt, std::vector<Type>& vector)
{
  if (vt.vt == (VT_DISPATCH | VT_ARRAY))
  {
    SAFEARRAY* pSA = vt.parray;

    long lUBound = 0, lLBound = 0;
    VERIFY(SafeArrayGetUBound(pSA, 1, &lUBound) == S_OK);
    VERIFY(SafeArrayGetLBound(pSA, 1, &lLBound) == S_OK);
    long lSize = lUBound - lLBound + 1;

    if (lSize > 0)
    {
      LPDISPATCH* pData = nullptr;
      HRESULT hRes = SafeArrayAccessData(pSA, (void**)&pData);
      VERIFY(hRes == S_OK);
      if (hRes == S_OK)
      {
        vector.reserve(lSize);
        for (long i = 0; i < lSize; i++)
        {
          Type pObject = pData[i];
          if (pObject)
            vector.push_back(pObject);
        }

        VERIFY(SafeArrayUnaccessData(pSA) == S_OK);
      }
    }
  }
  else if (vt.vt == VT_DISPATCH)
  {
    Type pObject = vt.pdispVal;
    if (pObject)
      vector.push_back(pObject);
  }
}




// ATreeCtrlEventCallBack #########################################################
//-----------------------------------------------------------------------------
// Обработка команд меню
// ---
void LibObj::OnMenuCommand(long Id)
{
  switch (Id)
  {
  case 502:  // Удалить стрелки
  {
    std::vector <IPropertyTreeNodePtr> nodeVector;
    FillVector(m_TreeCtrl->SelectedNodes, nodeVector);
    bool deleted = false;

    for (auto nodeIt = nodeVector.begin(); nodeIt != nodeVector.end();)
    {
      auto node = *nodeIt;

      for (auto arrowsIt = m_arrows.begin(); arrowsIt != m_arrows.end();)
      {
        auto param = *arrowsIt;

        if (param && node && node->NodeData == param->m_index)
        {
          OnOffTesselations(param->m_iids, false, param->m_visible, true); // Удаляем стрелки
          arrowsIt = m_arrows.erase(arrowsIt);
          m_arrrowsNode->DeleteNode(node);
          deleted = true;
          m_arrowsIndex--;

          break;
        }
        else
        {
          ++arrowsIt;
        }
      }

      nodeIt = nodeVector.erase(nodeIt);
    }

    if (deleted)
    {
      IDocumentFramePtr docFrame(GetFrame());

      for (size_t i = 0, count = m_arrows.size(); i < count; ++i)
        m_arrows[i]->m_index = i + 1;

      for (size_t i = 0, count = m_arrrowsNode->ChildsCount; i < count; ++i)
        m_arrrowsNode->Child[i]->NodeData = i + 1;


      docFrame->RefreshWindow();
    }

    SaveTree();

    break;
  }

  case 503: // Показать/Скрыть
  {
    std::vector <IPropertyTreeNodePtr> nodeVector;
    FillVector(m_TreeCtrl->SelectedNodes, nodeVector);

    for (auto nodeIt = nodeVector.begin(); nodeIt != nodeVector.end();)
    {
      auto node = *nodeIt;

      for (auto arrowsIt = m_arrows.begin(); arrowsIt != m_arrows.end();)
      {
        auto param = *arrowsIt;

        if (param && node && node->NodeData == param->m_index)
        {
          OnOffTesselations(param->m_iids, !param->m_visible, param->m_visible, false); // Показаем/Скрываем
          param->m_visible = !param->m_visible;
          break;
        }
        else
        {
          ++arrowsIt;
        }
      }

      ++nodeIt;
    }

    break;
  }
  }
}

void LibObj::OnBeginTextEdit(IPropertyTreeNodePtr node)
{
  if (node && ::YesNo("Отредактировать узел дерева?") == 1)
    node->EditText();
}

void LibObj::OnEndTextEdit(IPropertyTreeNodePtr node)
{
  if (node)
  {
    long index = node->NodeData;
    if (index > 0)
    {
      ArrowParam* param = m_arrows[index - 1];
      if (param)
        param->m_name = node->Text;
    }
  }
}

void LibObj::OnContextMenuRequest(IPropertyTreeNodePtr node)
{
  if (CheckIfArrowNode(node))
  {
    if (std::find(m_selectedNodes.begin(), m_selectedNodes.end(), node) == m_selectedNodes.end())
    {
      for (auto node : m_selectedNodes)
      {
        node->IsSelected = FALSE;
      }

      m_selectedNodes.clear();
      m_selectedNodes.push_back(node);
    }

    InitMenu(1);

  }
  else
    InitMenu(0);
}


//-----------------------------------------------------------------------------
// Развернуть\Свернуть
// ---
void LibObj::OnExpandOrCollapse(IPropertyTreeNodePtr node, bool collapse)
{
}


//-------------------------------------------------------------------------------------
// Клик по узлу дерева
// ---
void LibObj::InitMenu(int menuType)
{
  IPropertyControl1Ptr control1(m_TreeCtrl);
  if (control1)
  {
    // Если элемент это папка нагрузок
    if (menuType == 1)
    {
      CMenu* subMenu = m_treeMenu.GetSubMenu(0 /*индекс подменю*/);

      if (subMenu)
      {
        control1->UserMenu = subMenu ? PtrToLong(subMenu->m_hMenu) : 0l;
      }
    }
    else
      control1->UserMenu = 0l;
  }
}

void LibObj::OnSelectNodes(const VARIANT& Nodes)
{
  m_selectedNodes.clear();
  FillVector(m_TreeCtrl->SelectedNodes, m_selectedNodes);
}

void LibObj::OnUnselectNodes(const VARIANT& Nodes)
{
  std::vector <IPropertyTreeNodePtr> nodeVector;
  FillVector(m_TreeCtrl->SelectedNodes, nodeVector);
  for (auto node : nodeVector)
  {
    std::vector <IPropertyTreeNodePtr>::iterator it = std::find(m_selectedNodes.begin(), m_selectedNodes.end(), node);

    if (it != m_selectedNodes.end())
    {
      m_selectedNodes.erase(it);
    }
  }

}

// ATreeCtrlEventCallBack #########################################################


//-----------------------------------------------------------------------------
// Сохранение параметров дерева в хранилище
// ---
void LibObj::SaveTree()
{
  IDocumentFramePtr docFrame(GetFrame());
  if (docFrame)
  {
    IKompasDocument3DPtr doc3D(docFrame->GetParent()->GetParent());
    if (doc3D)
    {
      IUserDataStoragesMngPtr storageMng = doc3D->GetUserDataStoragesMng();
      if (storageMng)
      {
        IUserDataStoragesPtr storages = storageMng->Add(NULL);
        if (storages)
        {
          _bstr_t treeName(FORCES_TREE);
          IUserDataStoragePtr treePars = storages->Item[treeName];
          if (treePars)
            treePars->Clear(treeName);
          else
          {
            treePars = storages->Add(treeName);
            if (treePars)
              treePars->SetPassword(_bstr_t(), treeName);
          }
          if (treePars)
          {
            treePars->Version[treeName] = LIBVERSION; // Версия параметров
            treePars->AddObject(treeName, m_arrowsIndex, _bstr_t(_T("arrowsIndex")));   // Индекс следующей нагрузки 
            treePars->AddObject(treeName, (long)m_arrows.size(), _bstr_t(_T("arrowsCount")));   // Количество нагрузок
            for (int i = 0, count = m_arrows.size(); i < count; i++)
              m_arrows[i]->Save(treeName, treePars);
          }
        }
      }
    }
  }
}


//-----------------------------------------------------------------------------
// Получение значения по индексу
// ---
_variant_t GetObj(IUserDataStoragePtr& treePars, const _bstr_t& comment)
{
  _variant_t obj;
  long       num;
  treePars->GetObject(comment, &obj, &num);
  return obj;
}

IUserDataStoragePtr LibObj::GetUserDataStorageByName(const _bstr_t& treeName)
{
  IUserDataStoragePtr treePars = nullptr;

  IDocumentFramePtr docFrame(GetFrame());
  if (docFrame)
  {
    IKompasDocument3DPtr doc3D(docFrame->GetParent()->GetParent());
    if (doc3D)
    {
      IUserDataStoragesMngPtr storageMng = doc3D->GetUserDataStoragesMng();
      if (storageMng)
      {
        IUserDataStoragesPtr storages = storageMng->Add(nullptr);
        if (storages)
          treePars = storages->Item[treeName];
      }
    }
  }

  return treePars;
}

//-----------------------------------------------------------------------------
// Загрузка параметров дерева из хранилища 
// ---
void LibObj::LoadTree()
{
  _bstr_t treeName(FORCES_TREE);
  IUserDataStoragePtr treePars = GetUserDataStorageByName(treeName);

  if (treePars)
  {
    long version = treePars->Version[treeName];  // Версия параметров
    if (version <= LIBVERSION)
    {
      long index = 0;

      m_arrowsIndex = GetObj(treePars, _bstr_t(_T("arrowsIndex"))); // Индекс следующей нагрузки 
      long count = GetObj(treePars, _bstr_t(_T("arrowsCount"))); // Количество нагрузок 


      for (long i = 0; i < count; i++)
      {
        ArrowParam* param = new ArrowParam;
        if (param->Load(treePars, version, i))
          m_arrows.push_back(param);
        else
          delete param; // Если что-то не начиталось  
      }

      /// Отсортируем нагрузки по возрастанию их индексов
      auto comp{ [](ArrowParam* const& first, ArrowParam* const& second) { return first->m_index < second->m_index; } };
      std::sort(begin(m_arrows), end(m_arrows), comp);

      MakeTessellations();
    }
  }
}


//-----------------------------------------------------------------------------
// Расчет триангуляций 
// ---
void LibObj::MakeTessellations()
{
  IDocumentFramePtr docFrame(GetFrame());
  if (docFrame)
  {
    LoadArrowParams();

    for (int i = 0, count = m_arrows.size(); i < count; i++)
      m_arrows[i]->Make(docFrame, arrowParams);

    docFrame->SetGabaritModifying();
    docFrame->RefreshWindow();
  }
}


//-----------------------------------------------------------------------------
// Пересчитать нагрузки
// ---
void LibObj::Refresh()
{
  OffAllTessellations();
  MakeTessellations();
}


//-----------------------------------------------------------------------------
// Сохранение параметров в хранилище
// ---
void TeselationNodeParam::Save(_bstr_t& pasword, IUserDataStoragePtr& s)
{
  if (s)
  {
    _bstr_t indexStr(m_index);
    s->AddObject(pasword, m_index, _bstr_t(_T("index")) + indexStr);    // Индекс 
    s->AddObject(pasword, m_visible, _bstr_t(_T("visible")) + indexStr);    // Видимость 
    long count = m_faces.Count();
    s->AddObject(pasword, count, _bstr_t(_T("facesCount")) + indexStr); // Количество граней 

    if (count)
    {
      _variant_t faces(CreateDispSafeArray(m_faces), false/*copy*/);
      s->AddObject(pasword, faces, _bstr_t(_T("faces")) + indexStr);    // Видимость
    }

    if (m_name.length() > 0)
      s->AddObject(pasword, m_name, _bstr_t(_T("name")) + indexStr);
  }
}


//-----------------------------------------------------------------------------
// Получение параметров из хранилища
// ---
bool TeselationNodeParam::Load(IUserDataStoragePtr& s, long version, long index)
{
  bool res = false;
  if (s)
  {
    _bstr_t indexStr(index + 1);
    m_index = GetObj(s, _bstr_t(_T("index")) + indexStr);   // Индекс 
    m_visible = GetObj(s, _bstr_t(_T("visible")) + indexStr);   // Видимость 
    long count = GetObj(s, _bstr_t(_T("facesCount")) + indexStr);   // Количество граней

    if (count)
    {
      _variant_t faces(GetObj(s, _bstr_t(_T("faces")) + indexStr));
      FillObjectsDefinitions(faces, m_faces);
    }

    m_name = GetObj(s, _bstr_t(_T("name")) + indexStr); // Имя соответствующего узла
    res = true;
  }

  return res;
}


#pragma warning( disable : 4786 )
//-----------------------------------------------------------------------------
// Расчет параметров создания стрелок для одной грани 
// ---
void ArrowParam::Make(IFaceDefinitionPtr& face, IDocumentFramePtr& frame, PArray<ExternalTeselationParam>& arrowParams)
{
  if (face)
  {
    IKompasDocument3DPtr doc3D(frame->GetParent()->GetParent());
    IExternalTessellationManagerPtr mng(doc3D);
    if (mng)
    {
      SArray<Matrix3D> matrix;
      ISurfacePtr surf(face->GetSurface(), false/*AddRef*/);

      // Расчет матриц для отрисовки стрелок
      MakeMatrixes(surf, !!face->GetNormalOrientation(), matrix);

      if (doc3D->GetDocumentType() == ksDocumentAssembly)
      {
        // если грань принадлежит детали вставленной в сторку то нужно домножить на суммарную матрицу пересчета координат
        // из детали в сборку
        Matrix3D summMtr;
        if (GetSummMtr(doc3D, summMtr, face))
        {
          for (int i = 0, count = matrix.Count(); i < count; i++)
          {
            matrix[i] *= summMtr;
          }
        }
      }
      _variant_t matrixes(CreateSafeArray(matrix), false/*copy*/);
      SArray<long> objects;
      for (int i = 0, count = arrowParams.Count(); i < count; i++)
      {
        IExternalTessellationObjectPtr obj(mng->Add());
        if (obj)
        {
          long id = obj->ObjectID;
          objects.Add(id);
          arrowParams[i]->Init(obj);
          obj->SetPlaces(matrixes);
        }
      }
      if (m_visible)
      {
        _variant_t iids(CreateSafeArray(objects), false);
        mng->ObjectsVisible[iids][frame] = true;
      }
      m_iids += objects;
    }
  }
}
#pragma warning( once : 4786 ) 


//-----------------------------------------------------------------------------
// Расчет нагрузок
// ---
void ArrowParam::Make(IDocumentFramePtr& frame, PArray<ExternalTeselationParam>& arrowParams)
{
  if ((bool)frame && arrowParams.Count())
  {
    for (int i = 0, count = m_faces.Count(); i < count; i++)
      Make(*m_faces[i], frame, arrowParams);
  }
}




