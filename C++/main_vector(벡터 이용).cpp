#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
	//vector<vector<int> >�� ���� ������ ���� �о�� �� �ֽ��ϴ�.

	int i;
	vector<int> ans;
	
	for (i = 0; i < 2; i++) {
		if (v[0][i] == v[1][i]) {
			ans.push_back(v[2][i]);
		}
		else if (v[0][i] == v[2][i]) {
			ans.push_back(v[1][i]);
		}
		else {
			ans.push_back(v[0][i]);
		}
	}
	cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;
	return ans;
}
// vector push_back�ϰ� ���ٰ���
int main() {
	vector<vector<int>> v;
	vector<int> temp;
	
	temp.push_back(1);
	temp.push_back(4);

	v.push_back(temp);

	temp.clear();
	temp.push_back(3);
	temp.push_back(4);

	v.push_back(temp);

	temp.clear();
	temp.push_back(3);
	temp.push_back(10);

	v.push_back(temp);

	temp = solution(v);

	cout << temp[0] << temp[1] << endl;
}