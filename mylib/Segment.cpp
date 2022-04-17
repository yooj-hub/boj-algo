#include <iostream>
#include<vector>
#define NUMBER 12

using namespace std;

int a[] = {1,9,3,8,4,5,5,9,10,3,4,5};
int tree[4*NUMBER];

int init(int start, int end, int node){
    if(start == end) return tree[node] = a[start];
    int mid = (start+end)/2;
    return tree[node] = init(start,mid,node*2) + init(mid+1, end, node*2+1);
}
/**
 *
 * @param start 시작 인덱스
 * @param end 끝 인덱스
 * @param node 현재 노드 번호
 * @param left 구간합 시작 인덱스
 * @param right 구간합 끝 인덱스
 * @return
 */
int sum(int start, int end, int node, int left, int right){
    if(left >end || start>right) return 0;
    if(left <=start && end <=right) return tree[node];
    int mid = (start+end)/2;
    return sum(start, mid, node*2, left,right) + sum(mid+1,end, node*2+1, left,right);
}

void update(int start, int end, int node, int index, int diff){
    if(index < start || index>end) return;
    tree[node] +=diff;
    if(start == end) return;
    int mid = (start+end)/2;
    update(start,mid, node*2, index, diff);
    update(mid+1,end,node*2+1, index, diff);
}


int main(){
    init(0,NUMBER-1,1);
    cout << "0 부터 12까지의 구간합 : " << sum(0, NUMBER - 1, 1, 0, 12) << '\n';
    cout << "3 부터 8까지의 구간합 : " << sum(0, NUMBER-1, 1, 3, 8) << '\n';
    cout << "인덱스 5의 원소를 -5만큼 수정" << '\n';
    update(0,NUMBER-1, 1,5,-5);
    cout << "3부터 8 까지의 구간합 : " << sum(0, NUMBER-1, 1, 3, 8) << '\n';



}