#ifndef MOCK_H
#define MOCK_H

#include <QtTest>

const int LIMIT = 128;

typedef void (*FunctionPointer)();

class Object
{
	public:
		Object(void **newVf)
		{
			void (Object::*stubMethod)() = &Object::stub;

			for (int i = 0; i < LIMIT; i++)
			{
				newVf[i] = *(void **)&stubMethod;
			}

			*(void **)this = newVf;
		}

		void stub()
		{
			QFAIL("Attempted to call into a stub method");
		}

		template<class ...TArguments>
		void addInvocation(TArguments ...)
		{
		}
};

template<class T, class TReturn, class ...TArguments>
class MockSetup
{
	using ReturnCall = TReturn (MockSetup::*)();
	using ParameterCallbackCall = TReturn (MockSetup::*)(TArguments...);
	using CallbackCall = TReturn (MockSetup::*)();

	using ParameterCallback = TReturn (*)(T *, TArguments...);
	using Callback = TReturn (*)();

	public:
		MockSetup(void **vfptr, size_t index)
			: m_vfptr(vfptr)
			, m_index(index)
		{
		}

		void callback(ParameterCallback callback)
		{
			static ParameterCallbackCall callMethod = &MockSetup::parameterCallbackCall;

			s_parameterCallback = callback;
			m_vfptr[m_index] = *(void **)&callMethod;
		}

		void simpleCallback(Callback callback)
		{
			static CallbackCall callMethod = &MockSetup::callbackCall;

			s_callback = callback;
			m_vfptr[m_index] = *(void **)&callMethod;
		}

		void returns(TReturn value)
		{
			static ReturnCall callMethod = &MockSetup::returnCall;

			s_return = value;
			m_vfptr[m_index] = *(void **)&callMethod;
		}

		TReturn returnCall()
		{
			return s_return;
		}

		TReturn parameterCallbackCall(T *, TArguments ...arguments)
		{
			return s_parameterCallback(arguments...);
		}

		TReturn callbackCall()
		{
			return s_callback();
		}

	private:
		static TReturn s_return;
		static ParameterCallback s_parameterCallback;
		static Callback s_callback;

		void **m_vfptr;

		size_t m_index;
};

template<class T, class TReturn, class ...TArguments>
class MockSetup<T, TReturn &, TArguments...>
{
	using ReturnCall = TReturn &(MockSetup::*)();
	using ParameterCallbackCall = TReturn &(MockSetup::*)(T *, TArguments...);
	using CallbackCall = TReturn &(MockSetup::*)();

	using ParameterCallback = TReturn &(*)(TArguments...);
	using Callback = TReturn &(*)();

	public:
		MockSetup(void **vfptr, size_t index)
			: m_vfptr(vfptr)
			, m_index(index)
		{
		}

		void callback(ParameterCallback callback)
		{
			static ParameterCallbackCall callMethod = &MockSetup::parameterCallbackCall;

			s_parameterCallback = callback;
			m_vfptr[m_index] = *(void **)&callMethod;
		}

		void simpleCallback(Callback callback)
		{
			static CallbackCall callMethod = &MockSetup::callbackCall;

			s_parameterCallback = callback;
			m_vfptr[m_index] = *(void **)&callMethod;
		}

		void returns(TReturn &value)
		{
			static ReturnCall callMethod = &MockSetup::returnCall;

			s_return = &value;
			m_vfptr[m_index] = *(void **)&callMethod;
		}

		TReturn &returnCall()
		{
			return *s_return;
		}

		TReturn &parameterCallbackCall(T *, TArguments ...arguments)
		{
			return s_parameterCallback(arguments...);
		}

		TReturn &callbackCall(T *)
		{
			return s_parameterCallback();
		}

	private:
		static TReturn *s_return;
		static ParameterCallback s_parameterCallback;
		static Callback s_callback;

		void **m_vfptr;

		size_t m_index;
};

template<class T, class ...TArguments>
class MockSetup<T, void, TArguments...>
{
	using ParameterCallbackCall = void (MockSetup::*)(Object *, TArguments...);
	using CallbackCall = void (MockSetup::*)();

	using ParameterCallback = void (*)(TArguments...);
	using Callback = void (*)();

	public:
		MockSetup(void **vfptr, size_t index)
			: m_vfptr(vfptr)
			, m_index(index)
		{
		}

		void callback(ParameterCallback callback)
		{
			static ParameterCallbackCall callMethod = &MockSetup::parameterCallbackCall;

			s_parameterCallback = callback;
			m_vfptr[m_index] = *(void **)&callMethod;
		}

		void simpleCallback(Callback callback)
		{
			static CallbackCall callMethod = &MockSetup::callbackCall;

			s_parameterCallback = callback;
			m_vfptr[m_index] = *(void **)&callMethod;
		}

		MockSetup &verifiable()
		{
			static ParameterCallbackCall verifyMethod = &MockSetup::verifyCall;

			m_vfptr[m_index] = *(void **)&verifyMethod;

			return *this;
		}

		void parameterCallbackCall(Object *, TArguments ...arguments)
		{
			return s_parameterCallback(arguments...);
		}

		void callbackCall(Object *instance)
		{
			Q_UNUSED(instance);

			return s_parameterCallback();
		}

		void verifyCall(Object *instance, TArguments ...arguments)
		{
			instance->addInvocation(arguments...);
		}

	private:
		static ParameterCallback s_parameterCallback;
		static Callback s_callback;

		static bool s_invoked;

		void **m_vfptr;

		size_t m_index;
};

template<class T, class TReturn, class ...TArguments>
TReturn MockSetup<T, TReturn, TArguments...>::s_return;

template<class T, class TReturn, class ...TArguments>
typename MockSetup<T, TReturn, TArguments...>::Callback MockSetup<T, TReturn, TArguments...>::s_callback;

template<class T, class TReturn, class ...TArguments>
typename MockSetup<T, TReturn, TArguments...>::ParameterCallback MockSetup<T, TReturn, TArguments...>::s_parameterCallback;

template<class T, class TReturn, class ...TArguments>
TReturn *MockSetup<T, TReturn &, TArguments...>::s_return;

template<class T, class TReturn, class ...TArguments>
typename MockSetup<T, TReturn &, TArguments...>::Callback MockSetup<T, TReturn &, TArguments...>::s_callback;

template<class T, class TReturn, class ...TArguments>
typename MockSetup<T, TReturn &, TArguments...>::ParameterCallback MockSetup<T, TReturn &, TArguments...>::s_parameterCallback;

template<class T, class ...TArguments>
bool MockSetup<T, void, TArguments...>::s_invoked;

template<class T>
class Mock
{
	template<class TReturn, class ...TArguments>
	using Function = TReturn (T::*)(TArguments...);

	public:
		Mock()
			: m_object((void **)m_vfptr)
		{
		}

		template<class ...TArguments>
		MockSetup<T, void, TArguments...> setup(Function<void, TArguments...> function)
		{
			const size_t index = getIndex(function);

			return MockSetup<T, void, TArguments...>((void **)m_vfptr, index);
		}

		template<class TReturn, class ...TArguments>
		MockSetup<T, TReturn, TArguments...> setup(Function<TReturn, TArguments...> function)
		{
			const size_t index = getIndex(function);

			return MockSetup<T, TReturn, TArguments...>((void **)m_vfptr, index);
		}

		template<class ...TArguments>
		void verify(Function<void, TArguments...> function)
		{
			const size_t index = getIndex(function);

			Q_UNUSED(index);
		}

		template<class TFunction>
		size_t getIndex(TFunction function)
		{
			return ((size_t)*(FunctionPointer *)&function) / sizeof(FunctionPointer);
		}

		T &object()
		{
			return (T&)m_object;
		}

	private:
		FunctionPointer m_vfptr[LIMIT];
		Object m_object;
};

#endif // MOCK_H
