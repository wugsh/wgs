template<class T>
class CBTree 
{
	private:
		static const int M = 3; 				//B树的最小度数
		static const int KEY_MAX = 2 * M - 1;  	//节点包含关键字的最大数
		static const int KEY_MIN = M - 1; 		//非根节点包含关键的最小个数
		static const int CHILD_MAX = KEY_MAX + 1; //孩子节点的最大个数
		static const int CHILD_MIN = KEY_MIN + 1;
		
}