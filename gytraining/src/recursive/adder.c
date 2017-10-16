/* keyword: 半加器 */

/* 半加器没有接收进位的输入端，全加器有进位输入端，
 * 在将两个多位二进制数相加时，除了最低位外，每一位
 * 都要考虑来自低位的进位，半加器则不用考虑，只需要
 * 考虑两个输入端相加即可。
 */

int add(int a, int b)
{
    if (b == 0) return a;
    int sum = a ^ b; // 相加但不進位
    int carry = (a & b) << 1; // 進位但不相加
    return add(sum, carry);
}
