/** Riccardo Rampon - 1195597 */

template<class T, typename Q = int>
class Pair{
	public:
		Pair(T tClass, int tQuantity);
		const T& getClass() const;
		const int& getQuantity() const;
		void setQuantity(int nQ);
		bool operator==(const Pair<T,Q>& pair) const;
		bool operator!=(const Pair<T,Q>& pair) const;
		//Pair<T,Q>& operator=(const Pair<T,Q>& pair);

	private:
		T tClass;
		int tQuantity;
};
